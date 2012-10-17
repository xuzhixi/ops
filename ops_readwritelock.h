//===============================================
/**
 *  @file OPS_ReadWriteLock.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:28
 *  Last   modified:  2012-10-17 08:19:28
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_READWRITELOCK_H
#define __OPS_READWRITELOCK_H

#include <pthread.h>

namespace OPS
{

class ReadWriteLock
{
	public:
		ReadWriteLock();
		~ReadWriteLock();
		bool rlock();
		bool tryRlock();
		bool wlock();
		bool tryWlock();
		bool unlock();

	private:
		ReadWriteLock(const ReadWriteLock &);
		ReadWriteLock &operator=(const ReadWriteLock &);
		pthread_rwlock_t rwlock;
};

};

#endif // __OPS_READWRITELOCK_H
