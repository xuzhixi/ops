//===============================================
/**
 *  @file OPS_Reactor.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-25 09:46:54
 *  Last   modified:  2012-10-31 14:18:49
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_Reactor_H
#define __OPS_Reactor_H

#include <sys/epoll.h>
#include <map>
#include "OPS_Socket.h"
#include "OPS_HashMap.h"

using std::map;

/// reactor 每次可以处理的最大事件个数
#define REACTOR_EVERY_HANDLE_MAX_COUNT 500

namespace OPS
{
class Reactor;
typedef void (*CallBack)(Socket *sk, Reactor *rat);

class Reactor
{
	class EventList
	{
		public:
			EventList()
			{
				this->sk = NULL;
				this->isDelEvt = false;
				this->isDelSk = false;
			}

			Socket *sk;
			struct epoll_event regEvt;
			map<unsigned int, CallBack> evtFuncMap;
			bool isDelEvt;						///< 是否已从epoll删除这个socket句柄
			bool isDelSk;						///< 是否删除socket
	};

	public:
		enum EventType{IN=EPOLLIN, OUT=EPOLLOUT, PRI=EPOLLPRI, ERR=EPOLLERR, HUP=EPOLLHUP, ET=EPOLLET, LT=0, ONESHO=EPOLLONESHOT };

		Reactor();
		virtual ~Reactor();
		void setUserData(void *data);
		void *getUserData();
		void init(int size, unsigned int mode=LT);
		bool add(Socket *sk, EventType type, CallBack func);
		bool mod(Socket *sk, EventType type, CallBack func);
		bool del(Socket *sk, EventType type);
		bool del(Socket *sk);
		bool delOwn(Socket *sk, bool isDelSk=true);	///< 在回调函数中删除socket自身的所有事件，要调用这个函数
		void eventLoop();			///< 进入事件循环
		void quit();				///< 退出事件循环

	private:
		int epfd;							///< epoll 句柄
		unsigned int mode;					///< 触发模式ET or LT
		HASH_MAP<int, EventList> regMap;	///< 记录已注册的事件
		struct epoll_event events[REACTOR_EVERY_HANDLE_MAX_COUNT];       ///< 记录已经触发的事件
		bool isQuit;						///< 是否退出事件循环
		void *userData;						///< 存放用户数据
};

}

#endif // __OPS_Reactor_H
