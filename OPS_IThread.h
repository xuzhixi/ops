//===============================================
/**
 *  @file OPS_IThread.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:51
 *  Last   modified:  2012-10-26 15:52:56
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
		IThread();
		virtual ~IThread();
		void setIsDetach(bool isDetach);
		bool getIsDetach();
		bool start();
		void stop();
		void join();
		unsigned long getThreadId();
	
	protected:
		virtual void run() = 0;
	
	private:
		static void *baseRun(void *param);
		pthread_t id;
		bool isDetach;
};

}

#endif // __OPS_ITHREAD_H
