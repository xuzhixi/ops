//===============================================
/**
 *  @file OPS_SharePtr.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-03 13:23:53
 *  Last   modified:  2012-11-06 23:40:01
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_SHAREPTR_H
#define __OPS_SHAREPTR_H

#include "OPS_Mutex.h"

namespace OPS
{
	template<class T>
	class SharePtr
	{
		public:
			SharePtr(T *p = NULL, bool isArray=false)
			{
				ptr = p;
				if ( ptr != NULL )
				{
					this->isArray = isArray;
					count = new int(1);
					mutex = new Mutex();
				}
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
					if ( this->ptr != sp.ptr )	// 实际的指针不相同
					{
						this->deleteOne();
						this->addOne( sp );
					}
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
				if ( sp.ptr != NULL )
				{
					sp.mutex->lock();
					*(sp.count) = *(sp.count) + 1;	// 引用计数加1
					sp.mutex->unlock();
					this->ptr = sp.ptr;
					this->isArray = sp.isArray;
					this->count = sp.count;
					this->mutex = sp.mutex;
				}
				else
				{
					this->ptr = NULL;
				}
			}

			void deleteOne()
			{
				if ( ptr != NULL )
				{
					mutex->lock();
					if ( *count > 1 )
					{
						*count = *count - 1;	// 引用计数减1
						mutex->unlock();
					}
					else
					{
						if ( this->isArray )
						{
							delete[] ptr;
						}
						else
						{
							delete ptr;
						}
						delete count;
						mutex->unlock();
						delete mutex;
					}
				}
			}

			T *ptr;			// 数据指针
			bool isArray;	// 是否数组指针
			int *count;		// 引用计数器
			Mutex *mutex;	// 引用计数器线程锁
	};
}

#endif // __OPS_SHAREPTR_H

