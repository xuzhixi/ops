//===============================================
/**
 *  @file OPS_TcpSocket.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:06
 *  Last   modified:  2012-11-02 09:59:50
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_TCPSOCKET_H
#define __OPS_TCPSOCKET_H

#include "OPS_Socket.h"
#include "OPS_IBuffer.h"
#include "OPS_Queue.h"

namespace OPS
{

class TcpSocket : public Socket
{
	class Package
	{
		public:
			Package(char *data, size_t dataLen)
			{
				this->data = data;
				this->len = dataLen;
			}

			~Package()
			{
				if ( data != NULL )
				{
					free( data );
				}
			}

			char *data;
			size_t len;
	};

	public:
		TcpSocket();
		~TcpSocket();
		bool init(const char *ip, unsigned int port, bool block);
		bool connect(const char *ip, unsigned int port);
		ssize_t send(const char *buf, size_t sendLen);
		ssize_t recv(char *buf, size_t bufLen);
		void setRecvBuffer(IBuffer *buf);
		IBuffer *getRecvBuffer();
		void sendToQueue(char *data, size_t sendLen);	///< 把数据发送到消息队列
		void flushQueue();		///< 把消息队列的信息发送出去，直到发送失败或队列为空
	
	private:
		IBuffer *recvBuffer;
		Queue<Package *> sendQueue;		///< 发送消息队列
};

}
#endif // __OPS_TCPSOCKET_H
