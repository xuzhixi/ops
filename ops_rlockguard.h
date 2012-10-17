//===============================================
/**
 *  @file OPS_RlockGuard.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:32
 *  Last   modified:  2012-10-17 08:19:32
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_RLOCKGUARD_H
#define __OPS_RLOCKGUARD_H

#include "OPS_ReadWriteLock.h"

namespace OPS
{

class RlockGuard
{
	public:
		explicit RlockGuard(ReadWriteLock *lock);
		~RlockGuard();
	
	private:
		RlockGuard(const RlockGuard &);				// 禁止调用复制构造函数
		RlockGuard &operator=(const RlockGuard &);	// 禁止进行赋值操作
		ReadWriteLock *rwlock;
};

}

#endif // __OPS_RLOCKGUARD_H
