//===============================================
/**
 *  @file OPS_IProcess.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:25
 *  Last   modified:  2012-10-30 03:51:07
 *
 *  Description: 
 */
//================================================

#include <errno.h>
#include <unistd.h>
#include "ky_log.h"
#include "OPS_IProcess.h"

namespace OPS
{

	IProcess::~IProcess()
	{
	}

	pid_t IProcess::currentPid()
	{
		return getpid();
	}

	bool IProcess::setDaemon(int curdir, int stdio)
	{
		if ( daemon(curdir, stdio) != 0 )
		{
			KY_LOG_WARN("set process(%d) daemon error", IProcess::currentPid());
			return false;
		}

		return true;
	}

	bool IProcess::bound(int sig, void (*callBack)(int))
	{
		if ( signal(sig, callBack) == SIG_ERR )
		{
			KY_LOG_WARN("signal bound fail, invalidated signal(%d)", sig);
			return false;
		}

		return true;
	}

	bool IProcess::sendSignal(pid_t pid, int sig)
	{
		if ( kill(pid, sig) != 0 )
		{
			KY_LOG_WARN("send signal(%d) to process(%d) fail", sig, pid);
			return false;
		}

		return true;
	}

	bool IProcess::chdir(const char * path)
	{
		if ( ::chdir(path) != 0 )
		{
			KY_LOG_WARN("change current dir fail, errno(%d)", errno);
			return false;
		}

		return true;
	}

	bool IProcess::chroot(const char * path)
	{
		if ( ::chroot(path) != 0 )
		{
			KY_LOG_WARN("change root dir fail, errno(%d)", errno);
			return false;
		}

		return true;
	}

	char *IProcess::getcwd(char * buf, size_t size)
	{
		return ::getcwd(buf, size);
	}
}
