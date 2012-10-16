#include "ky_log.h"
#include "OPS_TcpServer.h"
#include "OPS_TcpSocket.h"

using OPS::TcpServer;
using OPS::TcpSocket;

int main()
{
	TcpServer server;
	TcpSocket client;

	ky_log_open_default("stdout", "a", KY_LOG_LEVEL_ALL, 0, 0);
	if (server.init(SOCKET_ADDR_ANY, 8080, true) == false)
	{
		return -1;	
	}
	if (server.listened(1000) == false)
	{
		return -1;
	}

	while (1)
	{
		if ( server.accepted(client, true) )
		{
			KY_LOG_INFO("peerIp: %s peerPort: %d", client.getPeerIp(), client.getPeerPort());
			client.closed();
		}
	}
	ky_log_close_default();

	return 0;
}

