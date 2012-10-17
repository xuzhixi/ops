//===============================================
/**
 *  @file OPS_ThreadPool.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:12
 *  Last   modified:  2012-10-17 08:20:12
 *
 *  Description: 
 */
//================================================

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
