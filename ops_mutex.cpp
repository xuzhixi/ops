//===============================================
/**
 *  @file OPS_Mutex.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:58
 *  Last   modified:  2012-10-19 17:35:37
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_Mutex.h"

namespace OPS
{

Mutex::Mutex()
{
	int result;
	
	result = pthread_mutex_init( &(this->mutex), NULL );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_mutex_init error, errno: %d", result);
	}
}

Mutex::~Mutex()
{
	int result;

	result = pthread_mutex_destroy( &(this->mutex) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_mutex_destroy error, errno: %d", result);
	}
}

bool Mutex::lock()
{
	int result;

	result = pthread_mutex_lock( &(this->mutex) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_mutex_lock error, errno: %d", result);
		return false;
	}

	return true;
}

bool Mutex::trylock()
{
	int result;

	result = pthread_mutex_trylock( &(this->mutex) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_mutex_trylock error, errno: %d", result);
		return false;
	}

	return true;
}

bool Mutex::unlock()
{
	int result;

	result = pthread_mutex_unlock( &(this->mutex) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_mutex_unlock error, errno: %d", result);
		return false;
	}

	return true;
}

}
