#include "ky_log.h"
#include "OPS_Process.h"

using OPS::Process;

int main()
{
	OPS_PROCESS_POOL(10, {
		KY_LOG_INFO("this process pid: %d", Process::currentPid());
		return 0;
	});


	KY_LOG_INFO("sleep 5 second start");
	sleep(5);
	KY_LOG_INFO("sleep 5 second end");

	return 0;
}
