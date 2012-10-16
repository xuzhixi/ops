#include "ky_log.h"
#include "OPS_UdpSocket.h"

using OPS::UdpSocket;

int main()
{
	UdpSocket server;
	char buf[100];
	ssize_t recvSize;

	ky_log_open_default("stdout", "a", KY_LOG_LEVEL_ALL, 0, 0);
	if (server.init(SOCKET_ADDR_ANY, 8888, true) == false)
	{
		return -1;
	}
	
	while (1)
	{
		recvSize = server.recvfromed(buf, 100);
		if ( recvSize > 0 )
		{
			buf[recvSize] = '\0';
			KY_LOG_INFO("PeerIp: %s PeerPort: %d msg: %s", server.getPeerIp(), server.getPeerPort(), buf);
		}
	}
	ky_log_close_default();

	return 0;
}
