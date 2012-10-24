//===============================================
/**
 *  @file t_server.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 22:49:41
 *  Last   modified:  2012-10-23 22:49:41
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_TcpServer.h"
#include "OPS_TcpSocket.h"

using OPS::TcpServer;
using OPS::TcpSocket;

int main()
{
	TcpServer server;
	TcpSocket client;

	if (server.init(SOCKET_ADDR_ANY, 8080, true) == false)
	{
		return -1;	
	}
	if (server.listen(1000) == false)
	{
		return -1;
	}

	while (1)
	{
		if ( server.accept(client, true) )
		{
			KY_LOG_INFO("peerIp: %s peerPort: %d", client.getPeerIp(), client.getPeerPort());
			client.clos();
		}
	}

	return 0;
}

