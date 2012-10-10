#include "ops_wlockguard.h"

using OPS::WlockGuard;

WlockGuard::WlockGuard(ReadWriteLock *lock) : rwlock(lock)
{
	this->rwlock->wlock();	
}

WlockGuard::~WlockGuard()
{
	this->rwlock->unlock();
}

