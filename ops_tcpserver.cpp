//===============================================
/**
 *  @file OPS_TcpServer.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:01
 *  Last   modified:  2012-10-26 01:45:37
 *
 *  Description: 
 */
//================================================

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "ky_log.h"
#include "OPS_TcpServer.h"

namespace OPS
{

bool TcpServer::listen(int maxWaitCount)
{
	//监听进来的socket连接
	if (::listen(this->getFd(), maxWaitCount) == -1)
	{
		KY_LOG_ERROR("listen error");
		return false;
	}

	return true;
}

bool TcpServer::accept(TcpSocket &client, bool block)
{
	int fd;
	struct sockaddr_in addr;
	socklen_t addrLen;

	addrLen = sizeof(addr);
	//阻塞等待进来的连接
	if ((fd = ::accept(this->getFd(), (struct sockaddr *)&addr, &addrLen)) == -1)
	{
		if ( errno != EAGAIN )
		{
			KY_LOG_ERROR("socket accept error, errno(%d)", errno);
		}
		return false;
	}

	if ( block == false )
	{
		// 设置为非阻塞
		if ( Socket::setNonblock(fd) == false )
		{
			this->close();
			return false;
		}
	}

	client.setFd( fd );
	client.savePeer( addr );

	return true;
}

TcpSocket *TcpServer::accept(bool block)
{
	TcpSocket *sk = new TcpSocket();

	if ( this->accept(*sk, block) )
	{
		return sk;
	}

	delete sk;
	return NULL;
}

}
