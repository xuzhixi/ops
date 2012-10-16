#include "OPS_Mutex.h"
#include "OPS_MutexGuard.h"

using OPS::Mutex;
using OPS::MutexGuard;

int main()
{
	Mutex mutex;
	
	{
		MutexGuard lg(&mutex);
		//mutex.lock();
	}

	return 0;
}
