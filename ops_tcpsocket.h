//===============================================
/**
 *  @file OPS_TcpSocket.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:06
 *  Last   modified:  2012-10-23 22:47:10
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_TCPSOCKET_H
#define __OPS_TCPSOCKET_H

#include "OPS_Socket.h"
#include "OPS_IBuffer.h"

namespace OPS
{

class TcpSocket : public Socket
{
	public:
		TcpSocket();
		~TcpSocket();
		bool init(const char *ip, unsigned int port, bool block);
		bool connect(const char *ip, unsigned int port);
		ssize_t send(const char *buf, size_t sendLen);
		ssize_t recv(char *buf, size_t bufLen);
		void setBuffer(IBuffer *buf);
		IBuffer *getBuffer();
	
	private:
		IBuffer *buffer;
};

}
#endif // __OPS_TCPSOCKET_H
