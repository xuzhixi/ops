//===============================================
/**
 *  @file OPS_ReadWriteLock.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:29
 *  Last   modified:  2012-10-17 08:19:29
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_ReadWriteLock.h"

using OPS::ReadWriteLock;

ReadWriteLock::ReadWriteLock()
{
	int result;

	result = pthread_rwlock_init( &(this->rwlock), NULL );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_rwlock_init error, errno: %d", result);
	}
}

ReadWriteLock::~ReadWriteLock()
{
	int result;

	result = pthread_rwlock_destroy( &(this->rwlock) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_rwlock_destroy error, errno: %d", result);
	}
}

bool ReadWriteLock::rlock()
{
	int result;

	result = pthread_rwlock_rdlock( &(this->rwlock) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_rwlock_rdlock error, errno: %d", result);
		return false;
	}

	return true;
}

bool ReadWriteLock::tryRlock()
{
	int result;

	result = pthread_rwlock_tryrdlock( &(this->rwlock) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_rwlock_tryrdlock error, errno: %d", result);
		return false;
	}

	return true;
}

bool ReadWriteLock::wlock()
{
	int result;

	result = pthread_rwlock_wrlock( &(this->rwlock) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_rwlock_wrlock error, errno: %d", result);
		return false;
	}

	return true;
}

bool ReadWriteLock::tryWlock()
{
	int result;

	result = pthread_rwlock_trywrlock( &(this->rwlock) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_rwlock_trywrlock error, errno: %d", result);
		return false;
	}

	return true;
}

bool ReadWriteLock::unlock()
{
	int result;

	result = pthread_rwlock_unlock( &(this->rwlock) );
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_rwlock_unlock error, errno: %d", result);
		return false;
	}

	return true;
}
