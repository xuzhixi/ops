//===============================================
/**
 *  @file OPS_Mutex.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:57
 *  Last   modified:  2012-10-17 08:18:57
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_MUTEX_H
#define __OPS_MUTEX_H

#include <pthread.h>

namespace OPS
{

class Mutex
{
	friend class Condition;

	public:
		Mutex();
		~Mutex();
		bool lock();
		bool trylock();
		bool unlock();
	
	private:
		Mutex(const Mutex &);
		Mutex &operator=(const Mutex &);
		pthread_mutex_t mutex;
};

}
#endif // __OPS_MUTEX_H
