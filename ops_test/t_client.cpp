#include "ky_log.h"
#include "OPS_TcpSocket.h"

using OPS::TcpSocket;

int main()
{
	TcpSocket client;
	char buf[100];
	ssize_t recvSize;

	ky_log_open_default("stdout", "a", KY_LOG_LEVEL_ALL, 0, 0);
	if (client.init(SOCKET_ADDR_ANY, SOCKET_PORT_ANY, true) == false)
	{
		return -1;
	}
	if ( client.connected("192.168.136.132", 8080) == false )
	{
		return -1;
	}
	
	while (1)
	{
		recvSize = client.recved(buf, 100);
		if ( recvSize == 0 )
		{
			KY_LOG_INFO("close connect,localIp: %s localPort: %d", client.getLocalIp(), client.getLocalPort());
			client.closed();
			break;
		}
	}
	ky_log_close_default();

	return 0;
}

