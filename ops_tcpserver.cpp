#include <unistd.h>
#include <fcntl.h>
#include "ky_log.h"
#include "ops_tcpserver.h"

using OPS::Socket;
using OPS::TcpServer;

bool TcpServer::listened(int maxWaitCount)
{
	//监听进来的socket连接
	if (listen(this->getFd(), maxWaitCount) == -1)
	{
		KY_LOG_ERROR("listen error");
		return false;
	}

	return true;
}

bool TcpServer::accepted(TcpSocket &client, bool block)
{
	int fd;
	struct sockaddr_in addr;
	socklen_t addrLen;

	addrLen = sizeof(addr);
	//阻塞等待进来的连接
	if ((fd = accept(this->getFd(), (struct sockaddr *)&addr, &addrLen)) == -1)
	{
		KY_LOG_ERROR("accept error");
		return false;
	}

	if ( block == false )
	{
		// 设置为非阻塞
		if ( Socket::setNonblock(fd) == false )
		{
			close(fd);
			return false;
		}
	}

	client.setFd( fd );
	client.savePeer( addr );

	return true;
}
