//===============================================
/**
 *  @file OPS_WlockGuard.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:32
 *  Last   modified:  2012-10-17 08:20:32
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_WLOCKGUARD_H
#define __OPS_WLOCKGUARD_H

#include "OPS_ReadWriteLock.h"

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
