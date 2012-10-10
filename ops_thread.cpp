#include "ky_log.h"
#include "ops_thread.h"

using OPS::Thread;


Thread::~Thread()
{
}

bool Thread::start()
{
	int result;

	result = pthread_create( &(this->id), NULL, Thread::baseRun, this);
	if ( result != 0 )
	{
		KY_LOG_ERROR("pthread_create error, errno: %d", result);
		return false;
	}

	return true;
}

unsigned long Thread::getId()
{
	return this->id;
}

void *Thread::baseRun(void *param)
{
	Thread *thread = static_cast<Thread *>(param);

	thread->run();

	return NULL;
}
