//===============================================
/**
 *  @file OPS_TcpSocket.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:07
 *  Last   modified:  2012-11-07 11:33:37
 *
 *  Description: 
 */
//================================================

#include <netinet/tcp.h>
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
			SharePtr<Package> pk;
			sendQueue.pop( pk );
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

	bool TcpSocket::setSendBuffer(int bytes)
	{
		// 实际分配缓冲区大小是 2 * bytes, 因为Linux假定发送/接收缓冲区的一半用于内部的内核结构
		return setSockOpt(this->getFd(), SOL_SOCKET, SO_SNDBUF, (const char*)&bytes, sizeof(int));
	}

	int  TcpSocket::getSendBuffer()
	{
		int bytes;

		getSockOpt(this->getFd(), SOL_SOCKET, SO_SNDBUF, (void *)&bytes, sizeof(int));
		bytes /= 2;
		return bytes;
	}

	bool TcpSocket::setRecvBuffer(int bytes)
	{
		// 实际分配缓冲区大小是 2 * bytes, 因为Linux假定发送/接收缓冲区的一半用于内部的内核结构
		return setSockOpt(this->getFd(), SOL_SOCKET, SO_RCVBUF, (const char*)&bytes, sizeof(int));
	}

	int  TcpSocket::getRecvBuffer()
	{
		int bytes;

		getSockOpt(this->getFd(), SOL_SOCKET, SO_RCVBUF, (void *)&bytes, sizeof(int));
		bytes /= 2;
		return bytes;
	}

	bool TcpSocket::setDisableNagle(bool on)
	{
		int optval = (int)on;

		return setSockOpt(this->getFd(), IPPROTO_TCP, TCP_NODELAY, (const char*)&optval, sizeof(int));
	}

	bool  TcpSocket::getDisableNagle()
	{
		int optval;

		getSockOpt(this->getFd(), IPPROTO_TCP, TCP_NODELAY, (void *)&optval, sizeof(int));
		return optval;
	}

	bool TcpSocket::setCork(bool on)
	{
		int optval = (int)on;

		return setSockOpt(this->getFd(), IPPROTO_TCP, TCP_CORK, (const char*)&optval, sizeof(int));
	}

	bool  TcpSocket::getCork()
	{
		int optval;

		getSockOpt(this->getFd(), IPPROTO_TCP, TCP_CORK, (void *)&optval, sizeof(int));
		return optval;
	}

	void TcpSocket::setAppRecvBuffer(IBuffer *buf)
	{
		this->recvBuffer = buf;
	}

	IBuffer *TcpSocket::getAppRecvBuffer()
	{
		return this->recvBuffer;
	}

	void TcpSocket::sendToQueue(SharePtr<Package> pkg)
	{
		sendQueue.push( pkg );	
	}
	
	void TcpSocket::flushQueue()
	{
		ssize_t sendLen;

		while ( !sendQueue.empty() )
		{
			SharePtr<Package> pkg;
			sendQueue.pop( pkg );

			sendLen = this->send( pkg->data, pkg->len );
			if ( sendLen != (ssize_t)pkg->len )
			{
				if ( sendLen == -1 )	// 发送错误
				{
					KY_LOG_ERROR("socket(%d) send package error!", this->getFd());
					sendQueue.pushFront( pkg );			// 压入队列头部，下次继续发送
				}
				else	// 由于发送缓存区满，只发送了一部分
				{
					pkg->len -= sendLen;	// 计算剩余数据长度
					char *residue = (char *)malloc( pkg->len );
					memcpy(residue, pkg->data + sendLen, pkg->len);
					Package *newPkg = new Package(residue, pkg->len);
					sendQueue.pushFront( newPkg );		// 剩余数据，压入队列头部，下次继续发送
				}
				break;
			}
		}
	}
}
