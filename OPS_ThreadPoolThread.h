#ifndef __OPS_THREADPOOLTHREAD_H
#define __OPS_THREADPOOLTHREAD_H

#include "OPS_IThread.h"

namespace OPS
{
class ThreadPool;

class ThreadPoolThread : public IThread
{
	public:
		void setThreadPool(ThreadPool *tp);
		void setStop(bool is);

	protected:
		void run();
	
	private:
		ThreadPool *threadPool;
		bool needStop;
};

}

#endif // __OPS_THREADPOOLTHREAD_H
