//===============================================
/**
 *  @file OPS_Reactor.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-25 09:46:32
 *  Last   modified:  2012-10-29 14:38:25
 *
 *  Description: 
 */
//================================================

#include <errno.h>
#include "ky_log.h"
#include "OPS_Reactor.h"

namespace OPS
{

	Reactor::Reactor()
	{
		this->isQuit = false;
	}

	Reactor::~Reactor()
	{
	}

	void Reactor::setUserData(void *data)
	{
		this->userData = data;
	}

	void *Reactor::getUserData()
	{
		return this->userData;
	}

	void Reactor::init(int size, unsigned int mode)
	{
		this->epfd = epoll_create(size);     // 建立一个epoll,最多可以监听size个fd 
		if ( this->epfd == -1 )
		{
			KY_LOG_ERROR("epoll_create error, errno(%d)", errno);
		}
		this->mode = mode;					 // ET or LT
	}

	bool Reactor::add(Socket *sk, EventType type, CallBack func)
	{
		int fd = sk->getFd();

		map<int, EventList>::iterator regMapIter = this->regMap.find(fd);
		if ( regMapIter != this->regMap.end() )
		{	
			EventList &evtList = regMapIter->second;

			if ( evtList.evtFuncMap.find( type ) != evtList.evtFuncMap.end() )
			{
				KY_LOG_WARN("socket(%d) event(%d) already register in this reactor! epoll(%d)", fd, type, this->epfd);
				return false;
			}
			else
			{
				struct epoll_event regEvent;

				regEvent.data.fd = fd;
				regEvent.events = evtList.regEvt.events | type;
				if ( epoll_ctl(this->epfd, EPOLL_CTL_MOD, fd, &regEvent) != 0 )   //修改epoll事件
				{
					KY_LOG_ERROR("modify epoll event error, epoll(%d) socket(%d) event(%d) errno(%d)", this->epfd, fd, type, errno);
					return false;
				}

				evtList.regEvt.events = regEvent.events;
				evtList.evtFuncMap[type] = func;
				return true;
			}
		}
		else
		{
			struct epoll_event regEvent;

			regEvent.data.fd = fd;
			regEvent.events = this->mode | type;
			if ( epoll_ctl(this->epfd, EPOLL_CTL_ADD, fd, &regEvent) != 0 )   //注册epoll事件
			{
				KY_LOG_ERROR("add epoll event error, epoll(%d) socket(%d) event(%d) errno(%d)", this->epfd, fd, type, errno);
				return false;
			}

			EventList evtList;
			evtList.sk = sk;
			evtList.regEvt = regEvent; 
			evtList.evtFuncMap[type] = func;

			this->regMap[fd] = evtList;
			return true;
		}
	}

	bool Reactor::mod(Socket *sk, EventType type, CallBack func)
	{
		int fd = sk->getFd();

		map<int, EventList>::iterator regMapIter = this->regMap.find(fd);
		if ( regMapIter != this->regMap.end() )
		{
			EventList &evtList = regMapIter->second;

			map<unsigned int, CallBack>::iterator iter = evtList.evtFuncMap.find( type );
			if ( iter != evtList.evtFuncMap.end() )
			{
				iter->second = func;
				return true;
			}
		}

		return false;
	}

	bool Reactor::del(Socket *sk, EventType type)
	{
		int fd = sk->getFd();

		map<int, EventList>::iterator regMapIter = this->regMap.find(fd);
		if ( regMapIter != this->regMap.end() )
		{
			EventList &evtList = regMapIter->second;

			if ( evtList.evtFuncMap.find( type ) != evtList.evtFuncMap.end() )
			{
				struct epoll_event regEvent;

				regEvent.data.fd = fd;
				regEvent.events = evtList.regEvt.events & (~type);
				if ( epoll_ctl(this->epfd, EPOLL_CTL_MOD, fd, &regEvent) != 0 )   //修改epoll事件
				{
					KY_LOG_ERROR("modify epoll event error, epoll(%d) socket(%d) event(%d) errno(%d)", this->epfd, fd, type, errno);
					return false;
				}

				evtList.regEvt.events = regEvent.events;
				evtList.evtFuncMap.erase( type );
				if ( evtList.evtFuncMap.empty() )
				{
					if ( epoll_ctl(this->epfd, EPOLL_CTL_DEL, fd, NULL) != 0 )	//从epoll中删除fd
					{
						KY_LOG_ERROR("delete epoll event error, epoll(%d) socket(%d) errno(%d)", this->epfd, fd, errno);
						return false;
					}
					this->regMap.erase( fd );
				}
				return true;
			}
		}

		return false;
	}

	bool Reactor::del(Socket *sk)
	{
		int fd = sk->getFd();

		if ( this->regMap.find(fd) != this->regMap.end() )
		{
			if ( epoll_ctl(this->epfd, EPOLL_CTL_DEL, fd, NULL) != 0 )  // 从epoll中删除fd
			{
				KY_LOG_ERROR("delete epoll event error, epoll(%d) socket(%d) errno(%d)", this->epfd, fd, errno);
				return false;
			}

			this->regMap.erase( fd );
			return true;
		}

		return false;
	}

	bool Reactor::delOwn(Socket *sk, bool isDelSk)
	{
		map<int, EventList>::iterator iter = this->regMap.find( sk->getFd() );
		if ( iter != this->regMap.end() )
		{
			iter->second.isDelEvt = true;
			iter->second.isDelSk = isDelSk;
			return true;
		}

		KY_LOG_WARN("can no found socket(%d), delOwn fail", sk->getFd());
		return false;
	}

	void Reactor::eventLoop()
	{
		int eventCount;

		while(1)
		{
			// 等待有事件发生
			eventCount = epoll_wait(this->epfd, this->events, REACTOR_EVERY_HANDLE_MAX_COUNT, -1);	// -1表示阻塞等待
			for (int i=0; i<eventCount; i++)
			{
				map<int, EventList>::iterator regMapIter = regMap.find( events[i].data.fd );
				if ( regMapIter != regMap.end() )
				{
					EventList &evtList = regMapIter->second;

					map<unsigned int, CallBack>::iterator iter;
					for (iter=evtList.evtFuncMap.begin(); iter!=evtList.evtFuncMap.end(); iter++)
					{
						if ( events[i].events & iter->first )
						{
							iter->second(evtList.sk, this);		// 调用注册的回调函数
							if ( evtList.isDelEvt )
							{
								Socket *socket = evtList.sk;
								bool delSocket = evtList.isDelSk;

								this->del(socket);	// 删除事件
								if ( delSocket )	// 删除socket
								{
									socket->close();
									delete socket;
								}
								break;
							}
						}
					}
				}
				else
				{
					KY_LOG_WARN("this socket(%d) is not register in reactor!", events[i].data.fd);
				}
			}

			if ( this->isQuit )
			{
				break;
			}
		}
	}

	void Reactor::quit()
	{
		this->isQuit = true;
	}
}
