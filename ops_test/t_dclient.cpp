#include <string.h>
#include "ky_log.h"
#include "ops_udpsocket.h"

using OPS::UdpSocket;

int main()
{
	UdpSocket client;
	char buf[100];

	ky_log_open_default("stdout", "a", KY_LOG_LEVEL_ALL, 0, 0);
	if (client.init(SOCKET_ADDR_ANY, SOCKET_PORT_ANY, true) == false)
	{
		return -1;
	}
	sprintf(buf, "Hello World!");
	if ( client.sendtoed("192.168.136.132", 8888, buf, strlen(buf)) < 0 )
	{
		KY_LOG_ERROR("send msg error!");
		return -1;
	}
	else
	{
		KY_LOG_INFO("LocalIp: %s LocalPort: %d send msg succefully!", client.getLocalIp(), client.getLocalPort());
	}
	ky_log_close_default();

	return 0;
}
