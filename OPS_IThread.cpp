#include "ky_log.h"
#include "OPS_IThread.h"

using OPS::IThread;


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
