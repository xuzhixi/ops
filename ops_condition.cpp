//===============================================
/**
 *  @file OPS_Condition.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:42
 *  Last   modified:  2012-10-19 17:33:20
 *
 *  Description: 
 */
//================================================

#include <errno.h>
#include <time.h>
#include "ky_log.h"
#include "OPS_Condition.h"

namespace OPS
{

Condition::Condition()
{
	int result;

	result = pthread_cond_init( &(this->cond), NULL );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_cond_init error, errno: %d", result);
	}
}

Condition::~Condition()
{
	int result;

	result = pthread_cond_destroy( &(this->cond) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_cond_destroy error, errno: %d", result);
	}
}

bool Condition::wait(Mutex &m)
{
	int result;

	result = pthread_cond_wait( &(this->cond), &(m.mutex) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_cond_wait error, errno: %d", result);
		return false;
	}

	return true;
}

bool Condition::timeWait(Mutex &m, long sec, long nsec, bool *isTimeout)
{
	struct timespec timeout;
	int result;

	if ( isTimeout != NULL )
	{
		*isTimeout = false;
	}

	clock_gettime(CLOCK_REALTIME, &timeout);
	timeout.tv_sec += sec;
	timeout.tv_nsec += nsec;
	result = pthread_cond_timedwait( &(this->cond), &(m.mutex), &timeout );
	if ( result != 0 )
	{
		if ( result == ETIMEDOUT )
		{
			KY_LOG_WARN("pthread_cond_timedwait, timeout(sec: %lu, nsec: %lu)", sec, nsec);
			if ( isTimeout != NULL )
			{
				*isTimeout = true;
			}
		}
		else
		{
			KY_LOG_ERROR("pthread_cond_timedwait error, errno: %d", result);
		}
		return false;
	}

	return true;
}

bool Condition::notify()
{
	int result;

	result = pthread_cond_signal( &(this->cond) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_cond_signal error, errno: %d", result);
		return false;
	}

	return true;
}

bool Condition::notifyAll()
{
	int result;

	result = pthread_cond_broadcast( &(this->cond) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_cond_broadcast error, errno: %d", result);
		return false;
	}

	return true;
}

}
