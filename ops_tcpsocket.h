//===============================================
/**
 *  @file OPS_TcpSocket.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:06
 *  Last   modified:  2012-11-07 10:45:25
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
#include "OPS_Package.h"

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
			bool setSendBuffer(int bytes);			///< 设置发送缓冲区的大小
			int  getSendBuffer();
			bool setRecvBuffer(int bytes);			///< 设置接收缓冲区的大小
			int  getRecvBuffer();
			bool setDisableNagle(bool on);			///< 是否禁用Nagle算法(Nagle算法默认是启用的)
			bool getDisableNagle();
			bool setCork(bool on);					///< 木塞,与Nagle的区别是，它不会超时; 只有发送缓存区的数据达到一定量的时候才进行发送(建议:需要时启用，用完后立刻关闭)
			bool getCork();
			void setAppRecvBuffer(IBuffer *buf);	///< 设置应用层的接收缓冲区
			IBuffer *getAppRecvBuffer();
			void sendToQueue(SharePtr<Package> pkg);	///< 把数据包发送到消息队列
			void flushQueue();		///< 把消息队列的信息发送出去，直到发送失败或队列为空

		private:
			IBuffer *recvBuffer;
			Queue< SharePtr<Package> > sendQueue;		///< 发送消息队列
	};
}

#endif // __OPS_TCPSOCKET_H

