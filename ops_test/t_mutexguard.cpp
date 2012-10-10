#include "ops_mutex.h"
#include "ops_mutexguard.h"

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
