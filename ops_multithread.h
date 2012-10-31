//===============================================
/**
 *  @file OPS_MultiThread.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 03:30:29
 *  Last   modified:  2012-10-30 04:16:15
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_MULTITHREAD_H
#define __OPS_MULTITHREAD_H

#include <sys/types.h>
#include "OPS_IThread.h"

using OPS::IThread;

namespace OPS
{

	template<class T>
	class MultiThread
	{
		public:
			MultiThread(size_t size)
			{
				this->threads = new T[size];
				this->size = size;
				this->isStart = false;
			}

			~MultiThread()
			{
				this->join();
				delete[] this->threads;
			}

			void start()
			{
				this->isStart = true;
				for (size_t i=0; i<(this->size); i++)
				{
					this->threads[i].start();
				}
			}

			void join()
			{
				if ( this->isStart )
				{
					this->isStart = false;
					for (size_t i=0; i<(this->size); i++)
					{
						this->threads[i].join();
					}
				}
			}

		private:
			MultiThread(const MultiThread &);
			MultiThread &operator=(const MultiThread &);

			size_t size;
			bool isStart;
			IThread *threads;
	};

}

#endif // __OPS_MULTITHREAD_H

