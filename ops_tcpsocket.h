//===============================================
/**
 *  @file OPS_TcpSocket.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:06
 *  Last   modified:  2012-10-17 08:20:06
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_TCPSOCKET_H
#define __OPS_TCPSOCKET_H

#include "OPS_Socket.h"

namespace OPS
{

class TcpSocket : public Socket
{
	public:
		bool init(const char *ip, unsigned int port, bool block);
		bool connected(const char *ip, unsigned int port);
		ssize_t sended(const char *buf, size_t sendLen);
		ssize_t recved(char *buf, size_t bufLen);
};

}
#endif // __OPS_TCPSOCKET_H
