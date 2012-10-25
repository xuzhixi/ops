//===============================================
/**
 *  @file OPS_UdpSocket.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:27
 *  Last   modified:  2012-10-26 02:01:16
 *
 *  Description: 
 */
//================================================

#include <errno.h>
#include "ky_log.h"
#include "OPS_UdpSocket.h"

namespace OPS
{

bool UdpSocket::init(const char *ip, unsigned int port, bool block)
{
	return Socket::init(ip, port, SOCKET_DGRAM, block);
}

ssize_t UdpSocket::sendto(const char *ip, unsigned int port, const void *buf, size_t sendLen)
{
	ssize_t result;
	struct sockaddr_in addr;
	int errno_bak;

	Socket::initSockAddr( addr, ip, port );
	result = ::sendto(this->getFd(), buf, sendLen, 0, (struct sockaddr *)&addr, sizeof(addr));
	errno_bak = errno;
	if ( (result == -1) && (errno != EAGAIN) )
	{
		KY_LOG_ERROR("socket(%d) sendto data error, errno(%d)", this->getFd(), errno);
	}
	this->savePeer( addr );
	errno = errno_bak;
	
	return result;
}

ssize_t UdpSocket::recvfrom(void *buf, size_t bufLen)
{
	ssize_t result;
	struct sockaddr_in addr;
	socklen_t addrLen;
	int errno_bak;

	addrLen = sizeof(addr);
	result = ::recvfrom(this->getFd(), buf, bufLen, 0, (struct sockaddr *)&addr, &addrLen);
	errno_bak = errno;
	if ( (result == -1) && (errno != EAGAIN) )
	{
		KY_LOG_ERROR("socket(%d) recvfrom data error, errno(%d)", this->getFd(), errno);
	}
	this->savePeer( addr );
	errno = errno_bak;

	return result;
}

}
