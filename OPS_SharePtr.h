//===============================================
/**
 *  @file OPS_SharePtr.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-03 13:23:53
 *  Last   modified:  2012-11-03 14:17:50
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_SHAREPTR_H
#define __OPS_SHAREPTR_H

#include "ky_log.h"
#include "OPS_Mutex.h"

namespace OPS
{
	template<class T>
	class SharePtr
	{
		public:
			SharePtr(T *p = NULL)
			{
				ptr = p;
				count = new int(1);
				mutex = new Mutex();
			}

			SharePtr(const SharePtr &sp)
			{
				this->addOne( sp );
			}

			~SharePtr()
			{
				this->deleteOne();
			}

			SharePtr &operator=(const SharePtr &sp)
			{
				if ( this != &sp )	// 非自身赋值
				{
					if ( this->ptr == sp.ptr )	// 实际的指针相同,则直接返回
					{
						return *this;
					}

					this->deleteOne();
					this->addOne( sp );
				}

				return *this;
			}

			T *&operator->()
			{
				return this->ptr;
			}

			friend bool operator==(const SharePtr &sp1, const SharePtr &sp2)
			{
				return sp1.ptr == sp2.ptr;
			}

			friend bool operator<(const SharePtr &sp1, const SharePtr &sp2)
			{
				return sp1.ptr < sp2.ptr;
			}

		private:
			void addOne(const SharePtr &sp)
			{
				sp.mutex->lock();
				*(sp.count) = *(sp.count) + 1;	// 引用计数加1
				sp.mutex->unlock();
				this->ptr = sp.ptr;
				this->count = sp.count;
				this->mutex = sp.mutex;
			}

			void deleteOne()
			{
				mutex->lock();				
				KY_LOG_INFO("SharePtr current count: %d", *count);
				if ( *count > 1 )
				{
					*count = *count - 1;	// 引用计数减1
					mutex->unlock();
				}
				else
				{
					if ( ptr != NULL )
					{
						KY_LOG_INFO("SharePtr delete data");
						delete ptr;
					}
					else
					{
						KY_LOG_INFO("SharePtr delete NULL");
					}
					delete count;
					mutex->unlock();
					delete mutex;
				}
			}

			T *ptr;			// 数据指针
			int *count;		// 引用计数器
			Mutex *mutex;	// 引用计数器线程锁
	};
}

#endif // __OPS_SHAREPTR_H

