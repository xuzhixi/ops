//===============================================
/**
 *  @file t_client.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 22:49:56
 *  Last   modified:  2012-10-25 13:19:10
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_TcpSocket.h"

using OPS::TcpSocket;

int main()
{
	TcpSocket client;
	char buf[100];
	ssize_t recvSize;

	if (client.init(SOCKET_ADDR_ANY, SOCKET_PORT_ANY, true) == false)
	{
		return -1;
	}
	if ( client.connect("192.168.136.132", 8080) == false )
	{
		return -1;
	}
	
	while (1)
	{
		recvSize = client.recv(buf, 100);
		if ( recvSize == 0 )
		{
			KY_LOG_INFO("close connect,localIp: %s localPort: %d", client.getLocalIp(), client.getLocalPort());
			client.close();
			break;
		}
	}

	return 0;
}

