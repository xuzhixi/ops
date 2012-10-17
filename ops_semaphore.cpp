//===============================================
/**
 *  @file OPS_Semaphore.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:39
 *  Last   modified:  2012-10-17 08:19:39
 *
 *  Description: 
 */
//================================================

#include <errno.h>
#include "ky_log.h"
#include "OPS_Semaphore.h"

using OPS::Semaphore;

Semaphore::Semaphore(unsigned int value)
{
	// 第二个参数为0表示信号量用于同一进程的线程间同步
	// 第三个参数表示初始化的信号量
	if ( sem_init( &(this->sem), 0, value ) != 0 )
	{
		KY_LOG_ERROR("sem_init error, errno: %d", errno);
	}
}

Semaphore::~Semaphore()
{
	if ( sem_destroy( &(this->sem) ) != 0 )
	{
		KY_LOG_ERROR("sem_destroy error, errno: %d", errno);
	}
}

bool Semaphore::post()
{
	if ( sem_post( &(this->sem) ) != 0 )
	{
		KY_LOG_ERROR("sem_post error, errno: %d", errno);
		return false;
	}

	return true;
}

bool Semaphore::release()
{
	if ( sem_wait( &(this->sem) ) != 0 )
	{
		KY_LOG_ERROR("sem_wait error, errno: %d", errno);
		return false;
	}

	return true;
}

bool Semaphore::tryRelease()
{
	if ( sem_trywait( &(this->sem) ) != 0 )
	{
		KY_LOG_ERROR("sem_trywait error, errno: %d", errno);
		return false;
	}

	return true;
}

bool Semaphore::getValue(int &val)
{
	if ( sem_getvalue( &(this->sem), &val ) != 0 )
	{
		KY_LOG_ERROR("sem_getvalue error, errno: %d", errno);
		return false;
	}

	return true;
}
