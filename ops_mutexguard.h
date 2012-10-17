//===============================================
/**
 *  @file OPS_MutexGuard.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:02
 *  Last   modified:  2012-10-17 08:19:02
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_MUTEXGUARD_H
#define __OPS_MUTEXGUARD_H

#include "OPS_Mutex.h"

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
