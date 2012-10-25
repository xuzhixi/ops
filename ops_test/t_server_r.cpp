//===============================================
/**
 *  @file t_server.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 22:49:41
 *  Last   modified:  2012-10-25 13:19:48
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_Socket.h"
#include "OPS_TcpServer.h"
#include "OPS_TcpSocket.h"
#include "OPS_Reactor.h"

using OPS::TcpServer;
using OPS::TcpSocket;
using OPS::Socket;
using OPS::Reactor;

void handle_connect(Socket *sk, Reactor *rat)
{
	TcpServer *server = (TcpServer *)sk;
	TcpSocket client;

	while ( server->accept(client, false) )
	{
		KY_LOG_INFO("peerIp: %s peerPort: %d", client.getPeerIp(), client.getPeerPort());
		client.close();
		//rat->delOwn( server );
		//rat->quit();
	}
}

int main()
{
	Reactor rat(1000, Reactor::ET);
	TcpServer server;
	TcpSocket client;

	if (server.init(SOCKET_ADDR_ANY, 8080, false) == false)
	{
		return -1;	
	}
	if (server.listen(1000) == false)
	{
		return -1;
	}
	
	rat.add( &server, Reactor::IN, handle_connect);	
	rat.eventLoop();

	return 0;
}

