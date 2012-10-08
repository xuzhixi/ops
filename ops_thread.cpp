#include "ky_log.h"
#include "ops_thread.h"

using OPS::Thread;

bool Thread::start()
{
	if ( pthread_create( &(this->id), NULL, Thread::baseRun, this) != 0 )
	{
		KY_LOG_ERROR("pthread_create error");
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
