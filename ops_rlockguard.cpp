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

