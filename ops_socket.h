#ifndef __OPS_SOCKET_H
#define __OPS_SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>

/// 表示任意的IP
#define SOCKET_ADDR_ANY "0.0.0.0"
/// 表示任意的端口 
#define SOCKET_PORT_ANY 0
/// TCP连接方式
#define SOCKET_STREAM   SOCK_STREAM
/// UDP连接方式
#define SOCKET_DGRAM    SOCK_DGRAM

namespace OPS
{

class Socket
{
	public:
		bool init(const char *ip, unsigned int port, int type, bool block);
		bool closed();
		void setFd(int fd);
		int getFd();
		const char *getLocalIp();
		unsigned int getLocalPort();
		const char *getPeerIp();
		unsigned int getPeerPort();
		void saveLocal(struct sockaddr_in &addr);		// 保存本地的IP和端口
		void savePeer(struct sockaddr_in &addr);		// 保存对方的IP和端口
		static void initSockAddr(struct sockaddr_in &addr, const char *ip, unsigned int port);	// 初始化sockaddr_in
		static bool setNonblock(int fd);

	private:
		int fd;							///< 操作的socket句柄
		char ip[16];					///< 本地IP
		unsigned int port;				///< 本地端口
		char peerIp[16];				///< 对方的IP
		unsigned int peerPort;			///< 对方的端口
};

}

#endif // __OPS_SOCKET_H
