//===============================================
/**
 *  @file OPS_TcpSocket.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:06
 *  Last   modified:  2012-11-03 13:53:47
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_TCPSOCKET_H
#define __OPS_TCPSOCKET_H

#include "OPS_Socket.h"
#include "OPS_IBuffer.h"
#include "OPS_Queue.h"
#include "OPS_SharePtr.h"

namespace OPS
{
	class Package
	{
		friend class TcpSocket;

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

		private:
			char *data;
			size_t len;
	};

	class TcpSocket : public Socket
	{
		public:
			TcpSocket();
			~TcpSocket();
			bool init(const char *ip, unsigned int port, bool block);
			bool connect(const char *ip, unsigned int port);
			ssize_t send(const char *buf, size_t sendLen);
			ssize_t recv(char *buf, size_t bufLen);
			void setRecvBuffer(IBuffer *buf);
			IBuffer *getRecvBuffer();
			void sendToQueue(SharePtr<Package> pkg);	///< 把数据包发送到消息队列
			void flushQueue();		///< 把消息队列的信息发送出去，直到发送失败或队列为空

		private:
			IBuffer *recvBuffer;
			Queue< SharePtr<Package> > sendQueue;		///< 发送消息队列
	};

}
#endif // __OPS_TCPSOCKET_H
