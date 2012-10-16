#include "OPS_ThreadPool.h"
#include "OPS_ThreadPool.hread.h"

using OPS::ThreadPool;
using OPS::ThreadPoolThread;

ThreadPool::ThreadPool(size_t size)
{
	this->threads = new ThreadPoolThread[size];
	for (size_t i=0; i<size; i++)
	{
		this->threads[i].setThreadPool( (ThreadPool *)this );
	}
	this->size = size;
	this->isStart = false;
}

ThreadPool::~ThreadPool()
{
	this->stop();
	delete[] this->threads;
}

void ThreadPool::addTask(Task *task)
{
	this->queue.push(task);
}

void ThreadPool::start()
{
	this->isStart = true;
	for (size_t i=0; i<(this->size); i++)
	{
		this->threads[i].start();
	}
}

void ThreadPool::stop()
{
	if ( this->isStart )
	{
		this->isStart = false;
		for (size_t i=0; i<(this->size); i++)
		{
			this->threads[i].setStop( true );
		}
	}
}
