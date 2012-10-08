#include "ky_log.h"
#include "ops_mutex.h"

using OPS::Mutex;

Mutex::Mutex()
{
	if ( pthread_mutex_init( &(this->mutex), NULL ) != 0 )
	{
		KY_LOG_ERROR("pthread_mutex_init error");
	}
}

Mutex::~Mutex()
{
	if ( pthread_mutex_destroy( &(this->mutex) ) != 0 )
	{
		KY_LOG_ERROR("pthread_mutex_destroy error");
	}
}

bool Mutex::lock()
{
	if ( pthread_mutex_lock( &(this->mutex) ) == 0 )
	{
		return true;
	}
	else
	{
		KY_LOG_ERROR("pthread_mutex_lock error");
		return false;
	}
}

bool Mutex::trylock()
{
	if ( pthread_mutex_trylock( &(this->mutex) ) == 0 )
	{
		return true;
	}
	else
	{
		KY_LOG_ERROR("pthread_mutex_trylock error");
		return false;
	}
}

bool Mutex::unlock()
{
	if ( pthread_mutex_unlock( &(this->mutex) ) == 0 )
	{
		return true;
	}
	else
	{
		KY_LOG_ERROR("pthread_mutex_unlock error");
		return false;
	}
}
