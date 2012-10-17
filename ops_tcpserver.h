//===============================================
/**
 *  @file OPS_TcpServer.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:00
 *  Last   modified:  2012-10-17 08:20:00
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_TCPSERVER_H
#define __OPS_TCPSERVER_H

#include "OPS_TcpSocket.h"

namespace OPS
{

class TcpServer : public TcpSocket
{
	public:
		bool listened(int maxWaitCount);
		bool accepted(TcpSocket &client, bool block);
};

}

#endif // __OPS_TCPSERVER_H
