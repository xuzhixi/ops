//===============================================
/**
 *  @file OPS_Socket.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:47
 *  Last   modified:  2012-11-07 11:34:07
 *
 *  Description: 
 */
//================================================

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include "ky_log.h"
#include "OPS_Socket.h"

namespace OPS
{

Socket::~Socket()
{
}

bool Socket::init(const char *ip, unsigned int port, int type, bool block)
{
	int optval = 1;
	struct sockaddr_in addr;
	socklen_t addrLen;

	if  ( (this->fd = socket(AF_INET, type, 0)) == -1 ) 
	{   
		KY_LOG_ERROR("socket error, errno(%d)", errno);
		return false;
	}   

	// SO_REUSEADDR 允许在bind()过程中本地地址可重复使用
	if ( !setSockOpt(this->fd, SOL_SOCKET, SO_REUSEADDR, (void *)&optval, sizeof(optval)) )
	{
		return false;
	}

	if ( block == false )
	{
		if ( this->setNonblock() == false )
		{
			return false;
		}
	}

	Socket::initSockAddr( addr, ip, port );

	if( bind(this->fd, (struct sockaddr *)&addr, sizeof(addr)) == -1 )
	{
		KY_LOG_ERROR("bind error, errno(%d)", errno);
		return false;
	}

	if ( port == SOCKET_PORT_ANY )
	{
		addrLen = sizeof(addr);
		// 如果端口为ANY，则获取系统所分配的端口
		getsockname(this->fd, (struct sockaddr *)&(addr), &addrLen);
	}

	//snprintf(this->ip, "%s", ip);
	this->saveLocal( addr );
	return true;
}

bool Socket::setSockOpt(int s, int level, int optname, const void *optval, socklen_t optlen)
{
	if ( setsockopt(s, level, optname, optval, optlen) != 0 )
	{
		KY_LOG_ERROR("setsockopt optname(%d) error, errno(%d)", optname, errno);
		return false;
	}
	
	return true;
}

bool Socket::getSockOpt(int s, int level, int optname, void *optval, socklen_t optlen)
{
	if ( getsockopt(s, level, optname, optval, &optlen) != 0 )
	{
		KY_LOG_ERROR("getsockopt optname(%d) error, errno(%d)", optname, errno);
		return false;
	}
	
	return true;
}

bool Socket::close()
{
	if ( ::close(this->fd) == 0 )
	{
		return true;
	}
	else
	{
		KY_LOG_ERROR("close socket(%d) error, errno(%d)", this->fd, errno);
		return false;
	}
}

void Socket::setFd(int fd)
{
	this->fd = fd;
}

int Socket::getFd()
{
	return this->fd;
}

void Socket::setName(const string &name)
{
	this->name = name;
}

string Socket::getName() const
{
	return this->name;
}

const char *Socket::getLocalIp()
{
	return this->ip;
}

unsigned int Socket::getLocalPort()
{
	return this->port;
}

unsigned int Socket::getPeerPort()
{
	return this->peerPort;
}

const char *Socket::getPeerIp()
{
	return this->peerIp;
}

void Socket::saveLocal(struct sockaddr_in &addr)
{
	inet_ntop(AF_INET, &(addr.sin_addr), this->ip, 16);
	this->port = ntohs(addr.sin_port);
}

void Socket::savePeer(struct sockaddr_in &addr)
{
	inet_ntop(AF_INET, &(addr.sin_addr), this->peerIp, 16);
	this->peerPort = ntohs(addr.sin_port);
}

bool Socket::setNonblock()
{
	return Socket::setNonblock( this->fd );
}

void Socket::initSockAddr(struct sockaddr_in &addr, const char *ip, unsigned int port)
{
	addr.sin_family = AF_INET;			    // 主机字节顺序
	addr.sin_port = htons(port);			// 把端口转换为网络字节顺序
	addr.sin_addr.s_addr = inet_addr(ip);
	bzero(&(addr.sin_zero), 8);				// 把不需要的位清零
}

bool Socket::setNonblock(int fd)
{
	int opts;

	opts = fcntl(fd, F_GETFL);
	if( opts == -1 )
	{
		KY_LOG_ERROR("set socketFd nonblock, fcntl(%d, F_GETFL) error, errno(%d)", fd, errno);
		return false;
	}

	opts = opts | O_NONBLOCK;
	if( fcntl(fd, F_SETFL, opts) == -1 )
	{
		KY_LOG_ERROR("set socketFd:%d nonblock error, errno(%d)", fd, errno);
		return false;
	}   

	return true; 
}

}
