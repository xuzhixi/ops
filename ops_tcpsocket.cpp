//===============================================
/**
 *  @file OPS_TcpSocket.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:07
 *  Last   modified:  2012-10-17 08:20:07
 *
 *  Description: 
 */
//================================================

#include "OPS_TcpSocket.h"

using OPS::TcpSocket;

bool TcpSocket::init(const char *ip, unsigned int port, bool block)
{
	return Socket::init(ip, port, SOCKET_STREAM, block);
}

bool TcpSocket::connected(const char *ip, unsigned int port)
{
	int result;
	struct sockaddr_in addr;

	Socket::initSockAddr( addr, ip, port );
	result = connect(this->getFd(), (struct sockaddr *)&addr, sizeof(addr));
	this->savePeer( addr );

	if ( result == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

ssize_t TcpSocket::sended(const char *buf, size_t sendLen)
{
	return send(this->getFd(), buf, sendLen, 0);
}

ssize_t TcpSocket::recved(char *buf, size_t bufLen)
{
	return recv(this->getFd(), buf, bufLen, 0);
}