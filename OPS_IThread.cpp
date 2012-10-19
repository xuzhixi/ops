//===============================================
/**
 *  @file OPS_IThread.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:52
 *  Last   modified:  2012-10-19 17:35:17
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_IThread.h"

namespace OPS
{

IThread::~IThread()
{
}

bool IThread::start()
{
	int result;

	result = pthread_create( &(this->id), NULL, IThread::baseRun, this);
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_create error, errno: %d", result);
		return false;
	}

	return true;
}

void IThread::stop()
{
}

unsigned long IThread::getThreadId()
{
	return this->id;
}

void *IThread::baseRun(void *param)
{
	IThread *thread = static_cast<IThread *>(param);

	thread->run();

	return NULL;
}

}
