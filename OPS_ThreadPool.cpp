//===============================================
/**
 *  @file OPS_ThreadPool.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:13
 *  Last   modified:  2012-10-27 03:49:13
 *
 *  Description: 
 */
//================================================

#include "OPS_ThreadPool.h"
#include "OPS_ThreadPoolThread.h"

namespace OPS
{

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
		for (size_t i=0; i<(this->size); i++)
		{
			this->threads[i].join();
		}
	}
}

}
