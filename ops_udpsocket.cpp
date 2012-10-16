#include "OPS_UdpSocket.h"

using OPS::UdpSocket;

bool UdpSocket::init(const char *ip, unsigned int port, bool block)
{
	return Socket::init(ip, port, SOCKET_DGRAM, block);
}

ssize_t UdpSocket::sendtoed(const char *ip, unsigned int port, const void *buf, size_t sendLen)
{
	ssize_t result;
	struct sockaddr_in addr;

	Socket::initSockAddr( addr, ip, port );
	result = sendto(this->getFd(), buf, sendLen, 0, (struct sockaddr *)&addr, sizeof(addr));
	this->savePeer( addr );
	
	return result;
}

ssize_t UdpSocket::recvfromed(void *buf, size_t bufLen)
{
	ssize_t result;
	struct sockaddr_in addr;
	socklen_t addrLen;

	addrLen = sizeof(addr);
	result = recvfrom(this->getFd(), buf, bufLen, 0, (struct sockaddr *)&addr, &addrLen);
	this->savePeer( addr );

	return result;
}
