//===============================================
/**
 *  @file OPS_WlockGuard.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:34
 *  Last   modified:  2012-10-17 08:20:34
 *
 *  Description: 
 */
//================================================

#include "OPS_WlockGuard.h"

using OPS::WlockGuard;

WlockGuard::WlockGuard(ReadWriteLock *lock) : rwlock(lock)
{
	this->rwlock->wlock();	
}

WlockGuard::~WlockGuard()
{
	this->rwlock->unlock();
}

