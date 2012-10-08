#ifndef __OPS_MUTEXGUARD_H
#define __OPS_MUTEXGUARD_H

#include "ops_mutex.h"

namespace OPS
{

class MutexGuard
{
	public:
		MutexGuard(Mutex *m);
		~MutexGuard();
	
	private:
		Mutex *mutex;
};

}

#endif // __OPS_MUTEXGUARD_H
