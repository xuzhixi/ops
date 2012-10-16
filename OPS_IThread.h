#ifndef __OPS_ITHREAD_H
#define __OPS_ITHREAD_H

#include <pthread.h>

namespace OPS
{

class IThread
{
	public:
		virtual ~IThread();
		bool start();
		void stop();
		unsigned long getThreadId();
	
	protected:
		virtual void run() = 0;
	
	private:
		static void *baseRun(void *param);
		pthread_t id;
};

}

#endif // __OPS_ITHREAD_H
