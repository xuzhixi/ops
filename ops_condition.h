#ifndef __OPS_CONDITION_H
#define __OPS_CONDITION_H

#include <pthread.h>
#include "OPS_Mutex.h"

using OPS::Mutex;

namespace OPS
{

class Condition
{
	public:
		Condition();
		~Condition();
		bool wait(Mutex &m);
		bool timeWait(Mutex &m, long sec, long usec, bool *isTimeout = NULL);
		bool notify();
		bool notifyAll();
	
	private:
		Condition(const Condition &);
		Condition &operator=(const Condition &);
		pthread_cond_t cond;
};

}

#endif // __OPS_CONDITION_H
