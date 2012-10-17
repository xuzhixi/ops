//===============================================
/**
 *  @file OPS_RlockGuard.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:34
 *  Last   modified:  2012-10-17 08:19:34
 *
 *  Description: 
 */
//================================================

#include "OPS_RlockGuard.h"

using OPS::RlockGuard;

RlockGuard::RlockGuard(ReadWriteLock *lock) : rwlock(lock)
{
	this->rwlock->rlock();	
}

RlockGuard::~RlockGuard()
{
	this->rwlock->unlock();
}

