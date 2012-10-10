#ifndef __OPS_WLOCKGUARD_H
#define __OPS_WLOCKGUARD_H

#include "ops_readwritelock.h"

namespace OPS
{

class WlockGuard
{
	public:
		explicit WlockGuard(ReadWriteLock *lock);
		~WlockGuard();
	
	private:
		WlockGuard(const WlockGuard &);				// 禁止调用复制构造函数
		WlockGuard &operator=(const WlockGuard &);	// 禁止进行赋值操作
		ReadWriteLock *rwlock;
};

}

#endif // __OPS_WLOCKGUARD_H
