#include <unistd.h>
#include "OPS_Process.h"

using OPS::Process;

long Process::currentPid()
{
	return (long)getpid();
}
