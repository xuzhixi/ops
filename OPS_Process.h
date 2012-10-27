//===============================================
/**
 *  @file OPS_Process.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:24
 *  Last   modified:  2012-10-27 15:15:09
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_PROCESS_H
#define __OPS_PROCESS_H

#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "ky_log.h"

namespace OPS
{
	class Process
	{
		public:
			virtual ~Process();
			virtual int run() = 0;

			static pid_t currentPid();
			/// 如果curdir的值为0，则将切换工作目录为根目录；如果stdio为0，则将标准输入，输出和标准错误都重定向到/dev/null
			static bool setDaemon(int curdir=0, int stdio=0);
			static bool bound(int sig, void (*callBack)(int));
			static bool sendSignal(pid_t pid, int sig);
	};

}

#endif // __OPS_PROCESS_H
