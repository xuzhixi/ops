//===============================================
/**
 *  @file OPS_TcpServer.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:00
 *  Last   modified:  2012-10-25 09:44:08
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
		bool listen(int maxWaitCount);
		bool accept(TcpSocket &client, bool block=true);
		/**
		 * @brief 成功返回一个TcpSocket连接(这个对象在不需要的时候，要手动delete)，否则返回NULL
		 */
		TcpSocket *accept(bool block=true);
};

}

#endif // __OPS_TCPSERVER_H
