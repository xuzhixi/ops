//===============================================
/**
 *  @file OPS_Socket.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:43
 *  Last   modified:  2012-11-01 14:11:42
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_SOCKET_H
#define __OPS_SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

/// 表示任意的IP
#define SOCKET_ADDR_ANY "0.0.0.0"
/// 表示任意的端口 
#define SOCKET_PORT_ANY 0
/// TCP连接方式
#define SOCKET_STREAM   SOCK_STREAM
/// UDP连接方式
#define SOCKET_DGRAM    SOCK_DGRAM

using std::string;

namespace OPS
{

class Socket
{
	public:
		~Socket();
		bool init(const char *ip, unsigned int port, int type, bool block);
		bool close();
		void setFd(int fd);
		int getFd();
		void setName(const string &name);
		string getName() const;
		const char *getLocalIp();
		unsigned int getLocalPort();
		const char *getPeerIp();
		unsigned int getPeerPort();
		void saveLocal(struct sockaddr_in &addr);		// 保存本地的IP和端口
		void savePeer(struct sockaddr_in &addr);		// 保存对方的IP和端口

		static void initSockAddr(struct sockaddr_in &addr, const char *ip, unsigned int port);	// 初始化sockaddr_in
		static bool setNonblock(int fd);

	private:
		string name;					///< 用户名
		int fd;							///< 操作的socket句柄
		char ip[16];					///< 本地IP
		unsigned int port;				///< 本地端口
		char peerIp[16];				///< 对方的IP
		unsigned int peerPort;			///< 对方的端口
};

}

#endif // __OPS_SOCKET_H
