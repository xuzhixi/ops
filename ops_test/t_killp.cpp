#include "OPS_Process.h"

using OPS::Process;

int main()
{
	Process::sendSignal(2469, SIGINT);

	return 0;
}
