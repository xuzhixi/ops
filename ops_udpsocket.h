//===============================================
/**
 *  @file OPS_UdpSocket.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:26
 *  Last   modified:  2012-10-23 22:48:48
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_UDPSOCKET_H
#define __OPS_UDPSOCKET_H

#include "OPS_Socket.h"

namespace OPS
{

class UdpSocket : public Socket
{
	public:
		bool init(const char *ip, unsigned int port, bool block);
		ssize_t sendto(const char *ip, unsigned int port, const void *buf, size_t sendLen);
		ssize_t recvfrom(void *buf, size_t bufLen);
};

}

#endif // __OPS_UDPSOCKET_H
