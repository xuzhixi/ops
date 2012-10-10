#ifndef __OPS_CONDITION_H
#define __OPS_CONDITION_H

#include <pthread.h>
#include "ops_mutex.h"

using OPS::Mutex;

namespace OPS
{

class Condition
{
	public:
		Condition();
		~Condition();
		bool wait(Mutex &m);
		bool timeWait(Mutex &m, unsigned long sec, unsigned long usec, bool *isTimeout = NULL);
		bool notify();
		bool notifyAll();
	
	private:
		Condition(const Condition &);
		Condition &operator=(const Condition &);
		pthread_cond_t cond;
};

}

#endif // __OPS_CONDITION_H
