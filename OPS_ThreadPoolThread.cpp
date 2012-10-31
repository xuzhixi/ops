//===============================================
/**
 *  @file OPS_ThreadPoolThread.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:19
 *  Last   modified:  2012-10-29 15:03:54
 *
 *  Description: 
 */
//================================================

#include "OPS_ThreadPool.h"
#include "OPS_ThreadPoolThread.h"
#include "OPS_Task.h"

namespace OPS
{

void ThreadPoolThread::setThreadPool(ThreadPool *tp)
{
	this->threadPool = tp;
	this->needStop = false; 
}

void ThreadPoolThread::setStop(bool is)
{
	this->needStop = is;
}

void ThreadPoolThread::run()
{
	Task *task;

	while (1)
	{
		if ( this->threadPool->queue.pop( task, 3 ) )	// 3秒超时
		{
			task->execute();
			delete task;
		}
		if ( this->needStop )
		{
			this->needStop = false;
			return;
		}
	}
}

}
