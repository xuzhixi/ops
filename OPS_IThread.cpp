//===============================================
/**
 *  @file OPS_IThread.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:52
 *  Last   modified:  2012-10-26 16:00:32
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_IThread.h"

namespace OPS
{

	IThread::IThread()
	{
		this->isDetach = false;
	}

	IThread::~IThread()
	{
	}


	void IThread::setIsDetach(bool isDetach)
	{
		this->isDetach = isDetach;
	}

	bool IThread::getIsDetach()
	{
		return this->isDetach;
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
		int result;

		result = pthread_cancel( this->id );		// 发信号让该线程退出，不阻塞
		if ( result != 0 )
		{
			KY_LOG_ERROR("pthread_cancel error, errno: %d", result);
		}
	}

	void IThread::join()
	{
		int result;

		result = pthread_join( this->id, NULL );	// 阻塞等待该线程退出
		if ( result != 0 )
		{
			KY_LOG_ERROR("pthread_join error, errno: %d", result);
		}
	}

	unsigned long IThread::getThreadId()
	{
		return this->id;
	}

	void *IThread::baseRun(void *param)
	{
		IThread *thread = static_cast<IThread *>(param);
		int result;

		if ( thread->getIsDetach() )
		{
			result = pthread_detach( pthread_self() );
			if ( result != 0 )
			{
				KY_LOG_ERROR("pthread_detach error, errno: %d", result);
			}
		}
		thread->run();

		return NULL;
	}

}
