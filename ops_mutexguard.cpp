#include "ops_mutexguard.h"

using OPS::MutexGuard;


MutexGuard::MutexGuard(Mutex *m) : mutex(m)
{
	this->mutex->lock();	
}

MutexGuard::~MutexGuard()
{
	this->mutex->unlock();
}

