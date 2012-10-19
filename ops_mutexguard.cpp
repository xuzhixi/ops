//===============================================
/**
 *  @file OPS_MutexGuard.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:03
 *  Last   modified:  2012-10-19 17:35:50
 *
 *  Description: 
 */
//================================================

#include "OPS_MutexGuard.h"

namespace OPS
{

MutexGuard::MutexGuard(Mutex *m) : mutex(m)
{
	this->mutex->lock();	
}

MutexGuard::~MutexGuard()
{
	this->mutex->unlock();
}

}
