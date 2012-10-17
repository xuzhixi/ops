//===============================================
/**
 *  @file OPS_ThreadPoolThread.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:18
 *  Last   modified:  2012-10-17 08:20:18
 *
 *  Description: 
 */
//================================================

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
