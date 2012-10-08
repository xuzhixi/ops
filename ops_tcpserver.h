#ifndef __OPS_TCPSERVER_H
#define __OPS_TCPSERVER_H

#include "ops_tcpsocket.h"

namespace OPS
{

class TcpServer : public TcpSocket
{
	public:
		bool listened(int maxWaitCount);
		bool accepted(TcpSocket &client, bool block);
};

}

#endif // __OPS_TCPSERVER_H
