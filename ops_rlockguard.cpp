#include "ops_rlockguard.h"

using OPS::RlockGuard;

RlockGuard::RlockGuard(ReadWriteLock *lock) : rwlock(lock)
{
	this->rwlock->rlock();	
}

RlockGuard::~RlockGuard()
{
	this->rwlock->unlock();
}

