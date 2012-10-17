//===============================================
/**
 *  @file OPS_IThread.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:51
 *  Last   modified:  2012-10-17 08:18:51
 *
 *  Description: 
 */
//================================================

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
