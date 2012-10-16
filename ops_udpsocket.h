#ifndef __OPS_UDPSOCKET_H
#define __OPS_UDPSOCKET_H

#include "OPS_Socket.h"

namespace OPS
{

class UdpSocket : public Socket
{
	public:
		bool init(const char *ip, unsigned int port, bool block);
		ssize_t sendtoed(const char *ip, unsigned int port, const void *buf, size_t sendLen);
		ssize_t recvfromed(void *buf, size_t bufLen);
};

}

#endif // __OPS_UDPSOCKET_H
