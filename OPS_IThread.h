//===============================================
/**
 *  @file OPS_IThread.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:51
 *  Last   modified:  2012-10-30 04:18:30
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_ITHREAD_H
#define __OPS_ITHREAD_H

#include <pthread.h>

#ifdef __linux
typedef pthread_t tid_t;
#endif

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
		tid_t getTid();
	
		static tid_t currentTid();

	protected:
		virtual void run() = 0;
	
	private:
		static void *baseRun(void *param);

		tid_t id;
		bool isDetach;
};

}

#endif // __OPS_ITHREAD_H
