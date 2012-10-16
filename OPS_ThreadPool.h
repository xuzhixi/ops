#ifndef __OPS_THREADPOOL_H
#define __OPS_THREADPOOL_H

#include "OPS_Task.h"
#include "OPS_PriorityQueue.h"

namespace OPS
{
class Task;
class ThreadPoolThread;

class ThreadPool
{
	friend class ThreadPoolThread;

	public:
		ThreadPool(size_t size);
		~ThreadPool();
		void addTask(Task *task);
		void start();
		void stop();
	
	private:
		size_t size;
		bool isStart;
		PriorityQueue<Task *, Task> queue;
		ThreadPoolThread *threads;
};

}

#endif // __OPS_THREADPOOL_H
