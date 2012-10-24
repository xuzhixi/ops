//===============================================
/**
 *  @file t_dserver.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 22:50:09
 *  Last   modified:  2012-10-23 22:50:09
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_UdpSocket.h"

using OPS::UdpSocket;

int main()
{
	UdpSocket server;
	char buf[100];
	ssize_t recvSize;

	if (server.init(SOCKET_ADDR_ANY, 8888, true) == false)
	{
		return -1;
	}
	
	while (1)
	{
		recvSize = server.recvfrom(buf, 100);
		if ( recvSize > 0 )
		{
			buf[recvSize] = '\0';
			KY_LOG_INFO("PeerIp: %s PeerPort: %d msg: %s", server.getPeerIp(), server.getPeerPort(), buf);
		}
	}

	return 0;
}
