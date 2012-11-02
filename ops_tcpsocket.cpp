//===============================================
/**
 *  @file OPS_TcpSocket.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:07
 *  Last   modified:  2012-11-02 10:08:41
 *
 *  Description: 
 */
//================================================

#include <errno.h>
#include "ky_log.h"
#include "OPS_TcpSocket.h"

namespace OPS
{
	TcpSocket::TcpSocket()
	{
		this->recvBuffer = NULL;
	}

	TcpSocket::~TcpSocket()
	{
		if ( this->recvBuffer != NULL )
		{
			delete recvBuffer;
		}
		while ( !sendQueue.empty() )
		{
			Package *pk = NULL;
			sendQueue.pop( pk );
			delete pk;
		}
	}

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
		return ::send(this->getFd(), buf, sendLen, 0);
	}

	ssize_t TcpSocket::recv(char *buf, size_t bufLen)
	{
		return ::recv(this->getFd(), buf, bufLen, 0);
	}

	void TcpSocket::setRecvBuffer(IBuffer *buf)
	{
		this->recvBuffer = buf;
	}

	IBuffer *TcpSocket::getRecvBuffer()
	{
		return this->recvBuffer;
	}

	void TcpSocket::sendToQueue(char *data, size_t sendLen)
	{
		Package *pk = new Package(data, sendLen);
		sendQueue.push( pk );	
	}
	
	void TcpSocket::flushQueue()
	{
		ssize_t sendLen;

		while ( !sendQueue.empty() )
		{
			Package *pk = NULL;
			sendQueue.pop( pk );

			sendLen = this->send( pk->data, pk->len );
			if ( sendLen != (ssize_t)pk->len )
			{
				if ( sendLen == -1 )	// 发送错误
				{
					KY_LOG_ERROR("socket(%d) send package error!", this->getFd());
				}
				else	// 由于发送缓存区满，只发送了一部分
				{
					pk->len -= sendLen;
					memcpy(pk->data, pk->data + sendLen, pk->len);
				}
				sendQueue.pushFront( pk );	// 压入队列头部，下次继续发送
				break;
			}
			delete pk;
		}
	}
}
