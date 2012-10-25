//===============================================
/**
 *  @file OPS_TcpSocket.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:07
 *  Last   modified:  2012-10-26 02:00:27
 *
 *  Description: 
 */
//================================================

#include <errno.h>
#include "ky_log.h"
#include "OPS_TcpSocket.h"

namespace OPS
{

bool TcpSocket::init(const char *ip, unsigned int port, bool block)
{
	return Socket::init(ip, port, SOCKET_STREAM, block);
}

bool TcpSocket::connect(const char *ip, unsigned int port)
{
	int result;
	struct sockaddr_in addr;

	Socket::initSockAddr( addr, ip, port );
	result = ::connect(this->getFd(), (struct sockaddr *)&addr, sizeof(addr));
	this->savePeer( addr );

	if ( result == 0 )
	{
		return true;
	}
	else
	{
		KY_LOG_WARN("connect remote server fail, errno: %d", errno);
		return false;
	}
}

ssize_t TcpSocket::send(const char *buf, size_t sendLen)
{
	ssize_t result;
	int errno_bak;

	result = ::send(this->getFd(), buf, sendLen, 0);
	errno_bak = errno;
	if ( (result == -1) && (errno != EAGAIN) )
	{
		KY_LOG_ERROR("socket(%d) send data error, errno(%d)", this->getFd(), errno);
	}
	errno = errno_bak;

	return result;
}

ssize_t TcpSocket::recv(char *buf, size_t bufLen)
{
	ssize_t result;
	int errno_bak;	

	result = ::recv(this->getFd(), buf, bufLen, 0);
	errno_bak = errno;
	if ( (result == -1) && (errno != EAGAIN) )
	{
		KY_LOG_ERROR("socket(%d) recv data error, errno(%d)", this->getFd(), errno);
	}
	errno = errno_bak;

	return result;
}

}
