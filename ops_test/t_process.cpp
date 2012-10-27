//===============================================
/**
 *  @file t_process.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-27 03:13:28
 *  Last   modified:  2012-10-27 15:17:56
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_Process.h"
#include "OPS_ProcessPool.h"

using OPS::Process;
using OPS::ProcessPool;

class Test : public Process
{
	public:
		int run()
		{
			KY_LOG_INFO("this process pid: %d", Process::currentPid());
			return 0;
		}
};

void handleSig(int sig)
{
	if ( sig == SIGINT )
	{
		KY_LOG_INFO("quit main process");
		exit(0);
	}
}

int main()
{
	char dir[50];
	Test ps;
	ProcessPool psPool;

	KY_LOG_INFO("current dir: %s", Process::getcwd(dir, 50));
	Process::setDaemon();
	KY_LOG_INFO("current dir: %s", Process::getcwd(dir, 50));
	psPool.start(10, &ps);
	Process::bound(SIGINT, handleSig);
	psPool.wait();

	while (1)
	{
		sleep(3);
	}

	return 0;
}
