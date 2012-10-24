//===============================================
/**
 *  @file t_dclient.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 22:50:21
 *  Last   modified:  2012-10-23 22:50:21
 *
 *  Description: 
 */
//================================================

#include <string.h>
#include "ky_log.h"
#include "OPS_UdpSocket.h"

using OPS::UdpSocket;

int main()
{
	UdpSocket client;
	char buf[100];

	if (client.init(SOCKET_ADDR_ANY, SOCKET_PORT_ANY, true) == false)
	{
		return -1;
	}
	sprintf(buf, "Hello World!");
	if ( client.sendto("192.168.136.132", 8888, buf, strlen(buf)) < 0 )
	{
		KY_LOG_ERROR("send msg error!");
		return -1;
	}
	else
	{
		KY_LOG_INFO("LocalIp: %s LocalPort: %d send msg succefully!", client.getLocalIp(), client.getLocalPort());
	}

	return 0;
}
