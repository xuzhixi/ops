//===============================================
/**
 *  @file OPS_IProcess.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:24
 *  Last   modified:  2012-10-30 03:48:30
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_IPROCESS_H
#define __OPS_IPROCESS_H

#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "ky_log.h"

namespace OPS
{
	class IProcess
	{
		public:
			virtual ~IProcess();
			virtual int run() = 0;

			static pid_t currentPid();
			/**
			 * 如果curdir的值为0，则将切换工作目录为根目录，否则不切换当前工作目录
			 * 如果stdio为0，则将标准输入，输出和标准错误都重定向到/dev/null, 否则不从定向标准输入、输出和标准错误
			 */
			static bool setDaemon(int curdir=1, int stdio=0);
			static bool bound(int sig, void (*callBack)(int));
			static bool sendSignal(pid_t pid, int sig);
			/// 改变当前工作目录
			static bool chdir(const char * path);
			/// 改变根目录, 只有超级用户才允许改变根目录，子进程将继承新的根目录
			static bool chroot(const char * path);
			/// 获取当前工作目录
			static char *getcwd(char * buf, size_t size);
	};
}

#endif // __OPS_IPROCESS_H
