//===============================================
/**
 *  @file OPS_Process.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:24
 *  Last   modified:  2012-10-26 15:40:20
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_PROCESS_H
#define __OPS_PROCESS_H

#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include "ky_log.h"

/**
 * @brief 创建进程池
 *
 * @param  count    进程的个数
 * @param  content  进程执行的操作(一般要在最后有个return操作)
 */
#define OPS_PROCESS_POOL(count, content) { \
	int __ops_i; \
	for(__ops_i=0; __ops_i<count; __ops_i++) { \
		pid_t __ops_pid = fork(); \
		if ( __ops_pid == 0 )\
		content \
		else if ( __ops_pid < 0 ) { \
			KY_LOG_ERROR("create progress error, errno(%d)", errno); \
		} \
	} \
}

namespace OPS
{

	class Process
	{
		public:
			static long currentPid();
	};

}

#endif // __OPS_PROCESS_H
