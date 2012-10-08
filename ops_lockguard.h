#ifndef __OPS_LOCKGUARD_H
#define __OPS_LOCKGUARD_H

#include "ops_mutex.h"

namespace OPS
{

template<class T>
class LockGuard
{
	public:
		explicit LockGuard(T *m) : mutex(m)
		{
			this->mutex->lock();	
		}

		~LockGuard()
		{
			this->mutex->unlock();
		}
	
	private:
		explicit LockGuard(const LockGuard &);		// 禁止调用复制构造函数
		LockGuard &operator=(const LockGuard &);	// 禁止进行复制操作
		T *mutex;
};

}

#endif // __OPS_LOCKGUARD_H
