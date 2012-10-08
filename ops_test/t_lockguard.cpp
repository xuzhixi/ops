#include "ops_mutex.h"
#include "ops_lockguard.h"

using OPS::Mutex;
using OPS::LockGuard;

int main()
{
	Mutex mutex;
	
	{
		LockGuard<Mutex> lg(&mutex);
	}

	return 0;
}
