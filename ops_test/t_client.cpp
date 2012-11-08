//===============================================
/**
 *  @file t_client.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 22:49:56
 *  Last   modified:  2012-11-07 10:46:31
 *
 *  Description: 
 */
//================================================

#include <errno.h>
#include "ky_log.h"
#include "OPS_TcpSocket.h"

using OPS::TcpSocket;

int main()
{
	TcpSocket client;
	char buf[3500];
	ssize_t recvSize;

	if (client.init(SOCKET_ADDR_ANY, SOCKET_PORT_ANY, true) == false)
	{
		return -1;
	}
	//client.setSendBuffer(1024);		// 设置发送缓冲区
	//client.setRecvBuffer(128);		// 设置接收缓冲区
	//client.setDisableNagle(true);		// 关闭Nagle
	//client.setCork(true);				// 设置木塞			
	KY_LOG_INFO("send buffer size: %d", client.getSendBuffer());
	KY_LOG_INFO("recv buffer size: %d", client.getRecvBuffer());
	if ( client.connect(SOCKET_ADDR_LOCAL, 8080) == false )
	{
		return -1;
	}
	//client.setNonblock();
	
	for(int i=0; i<1000; i++)
	{
		client.send(buf, 3500);
		//KY_LOG_INFO("3send package size: %d, errno(%d)", client.send(buf, 3), errno);
		//KY_LOG_INFO("3500send package size: %d, errno(%d)", client.send(buf, 3500), errno);
	}
	//for (int i=0; i<1000; i++)
	//{
	//	client.send("[5,12345]", 9);
	//}

	while (1)
	{
		recvSize = client.recv(buf, 100);
		if ( recvSize > 0 )
		{
			buf[recvSize] = '\0';
			KY_LOG_INFO("recv data: %s", buf);
		}
		else if ( recvSize == 0 )
		{
			KY_LOG_INFO("close connect,localIp: %s localPort: %d", client.getLocalIp(), client.getLocalPort());
			client.close();
			break;
		}
	}

	return 0;
}

