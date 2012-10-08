#ifndef __OPS_MUTEX_H
#define __OPS_MUTEX_H

#include <pthread.h>

namespace OPS
{

class Mutex
{
	public:
		Mutex();
		~Mutex();
		bool lock();
		bool trylock();
		bool unlock();
	
	private:
		pthread_mutex_t mutex;
};

}
#endif // __OPS_MUTEX_H
