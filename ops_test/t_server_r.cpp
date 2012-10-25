//===============================================
/**
 *  @file t_server.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 22:49:41
 *  Last   modified:  2012-10-25 23:48:48
 *
 *  Description: 
 */
//================================================

#include <errno.h>
#include "ky_log.h"
#include "OPS_Socket.h"
#include "OPS_TcpServer.h"
#include "OPS_TcpSocket.h"
#include "OPS_Reactor.h"

using OPS::TcpServer;
using OPS::TcpSocket;
using OPS::Socket;
using OPS::Reactor;


class TServer
{
	public:
		void start(const char *ip, unsigned int port)
		{
			if (server.init(ip, port, false) == false)
			{
				return;	
			}
			if (server.listen(1000) == false)
			{
				return;
			}

			rat.init(1000, Reactor::ET);
			rat.add( &server, Reactor::IN, TServer::handleConnect);	
			rat.eventLoop();
		}

	private:
		static void handleConnect(Socket *sk, Reactor *rat)
		{
			TcpServer *svr = (TcpServer *)sk;
			TcpSocket *client;

			while ( (client=svr->accept(false)) != NULL )
			{
				rat->add(client, Reactor::IN, TServer::readyRead);
				rat->add(client, Reactor::OUT, TServer::readyWrite);
				KY_LOG_INFO("coming connect socket(%d) peerIp: %s peerPort: %d", client->getFd(), client->getPeerIp(), client->getPeerPort());
			}

		}

		static void readyRead(Socket *sk, Reactor *rat)
		{
			TcpSocket *socket = (TcpSocket *)sk;
			char buf[512];
			ssize_t recvLen;

			KY_LOG_DEBUG("socket(%d)!", socket->getFd());
			while (1)
			{
				KY_LOG_DEBUG("socket(%d)!", socket->getFd());
				recvLen = socket->recv(buf, 512);

				if ( recvLen > 0 )			// 有数据可读
				{
					buf[recvLen] = '\0';
					KY_LOG_INFO("socket(%d) read data: %s", socket->getFd(), buf);
				}
				else if ( recvLen == 0 )	// socket连接断开
				{
					socket->close();
					rat->delOwn( socket );
					delete socket;
					break;
				}
				else
				{
					if ( errno != EAGAIN )	// 如果不是EAGAIN(表示没有可读数据), 表示发生错误
					{
						KY_LOG_ERROR("socket recv happen error, already close fd=%d", socket->getFd());
						socket->close();
						rat->delOwn( socket );
						delete socket;
					}
					break;
				}
			}
		}

		static void readyWrite(Socket *sk, Reactor *rat)
		{
			KY_LOG_INFO("readyWrite socket(%d)", sk->getFd());
		}

		TcpServer server;	
		Reactor rat;
};

int main()
{
	TServer server;

	server.start(SOCKET_ADDR_ANY, 8080);

	return 0;
}

