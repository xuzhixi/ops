//===============================================
/**
 *  @file OPS_ProcessPool.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-27 02:27:26
 *  Last   modified:  2012-10-27 03:18:18
 *
 *  Description: 
 */
//================================================

#include <sys/wait.h>
#include "ky_log.h"
#include "OPS_ProcessPool.h"
#include "OPS_Process.h"

namespace OPS
{
	void ProcessPool::start(int count, Process *ps)
	{
		for(int i=0; i<count; i++) 
		{ 
			pid_t pid = fork(); 
			if ( pid == 0 )			// 子进程
			{
				if ( ps != NULL )
				{
					exit( ps->run() );
				}
				exit(1);
			}
			else if ( pid > 0 )		// 父进程
			{
				this->pidVct.push_back( pid );
			}
			else if ( pid < 0 )		// 出错
			{ 
				KY_LOG_ERROR("create progress error, errno(%d)", errno); 
			} 
		} 
	}

	void ProcessPool::wait()
	{
		pid_t pid;
		int status;
		int exitCode;

		while ( (pid=::wait(&status)) != -1 )
		{
			exitCode = WEXITSTATUS(status);
			KY_LOG_INFO("progress(%d) quit, exitCode(%d)", pid, exitCode);
		}
	}

}
