//===============================================
/**
 *  @file OPS_Process.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:25
 *  Last   modified:  2012-10-27 15:15:07
 *
 *  Description: 
 */
//================================================

#include <unistd.h>
#include "ky_log.h"
#include "OPS_Process.h"

namespace OPS
{

	Process::~Process()
	{
	}

	pid_t Process::currentPid()
	{
		return getpid();
	}

	bool Process::setDaemon(int curdir, int stdio)
	{
		if ( daemon(curdir, stdio) != 0 )
		{
			KY_LOG_WARN("set process(%d) daemon error", Process::currentPid());
			return false;
		}

		return true;
	}

	bool Process::bound(int sig, void (*callBack)(int))
	{
		if ( signal(sig, callBack) == SIG_ERR )
		{
			KY_LOG_WARN("signal bound fail, invalidated signal(%d)", sig);
			return false;
		}

		return true;
	}

	bool Process::sendSignal(pid_t pid, int sig)
	{
		if ( kill(pid, sig) != 0 )
		{
			KY_LOG_WARN("send signal(%d) to process(%d) fail", sig, pid);
			return false;
		}

		return true;
	}
}
