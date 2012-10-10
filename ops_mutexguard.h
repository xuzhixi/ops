#ifndef __OPS_MUTEXGUARD_H
#define __OPS_MUTEXGUARD_H

#include "ops_mutex.h"

namespace OPS
{

class MutexGuard
{
	public:
		explicit MutexGuard(Mutex *m);
		~MutexGuard();
	
	private:
		MutexGuard(const MutexGuard &);				// 禁止调用复制构造函数
		MutexGuard &operator=(const MutexGuard &);	// 禁止进行赋值操作
		Mutex *mutex;
};

}

#endif // __OPS_MUTEXGUARD_H
