//===============================================
/**
 *  @file OPS_Queue.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-19 17:42:55
 *  Last   modified:  2012-11-02 10:22:17
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_Queue_H
#define __OPS_Queue_H

#include <list>
#include "OPS_Condition.h"
#include "OPS_Mutex.h"
#include "OPS_MutexGuard.h"

using std::list;

namespace OPS
{

template<class T>
class Queue
{
	public:
		Queue(size_t maxSize = 0)
		{
			this->maxSize = maxSize;
		}

		void pushFront(const T &val)
		{
			this->mutex.lock();
			while ( this->maxSize != 0 && this->que.size() == this->maxSize )
			{
				this->pushCond.wait( this->mutex );
			}
			this->que.push_front( val );
			this->mutex.unlock();
			this->popCond.notify();
		}

		bool pushFront(const T &val, long sec, long nsec = 0)
		{
			bool isTimeout;

			this->mutex.lock();
			while ( this->maxSize != 0 && this->que.size() == this->maxSize )
			{
				this->pushCond.timeWait( this->mutex, sec, nsec, &isTimeout);
				if ( isTimeout )
				{
					// 超时后，重新获得锁, 然后返回; 所以这里要先解锁，否则会导致死锁
					this->mutex.unlock();
					return false;
				}
			}
			this->que.push_front( val );
			this->mutex.unlock();
			this->popCond.notify();

			return true;
		}

		void push(const T &val)
		{
			this->mutex.lock();
			while ( this->maxSize != 0 && this->que.size() == this->maxSize )
			{
				this->pushCond.wait( this->mutex );
			}
			this->que.push_back( val );
			this->mutex.unlock();
			this->popCond.notify();
		}
		
		bool push(const T &val, long sec, long nsec = 0)
		{
			bool isTimeout;

			this->mutex.lock();
			while ( this->maxSize != 0 && this->que.size() == this->maxSize )
			{
				this->pushCond.timeWait( this->mutex, sec, nsec, &isTimeout);
				if ( isTimeout )
				{
					// 超时后，重新获得锁, 然后返回; 所以这里要先解锁，否则会导致死锁
					this->mutex.unlock();
					return false;
				}
			}
			this->que.push_back( val );
			this->mutex.unlock();
			this->popCond.notify();

			return true;
		}

		void pop(T &val)
		{
			this->mutex.lock();
			while ( this->que.size() == 0 )
			{
				this->popCond.wait( this->mutex );
			}
			val = this->que.front();
			this->que.pop_front();
			this->mutex.unlock();
			this->pushCond.notify();
		}

		bool pop(T &val, long sec, long nsec = 0)
		{
			bool isTimeout;

			this->mutex.lock();
			while ( this->que.size() == 0 )
			{
				this->popCond.timeWait( this->mutex, sec, nsec, &isTimeout );
				if ( isTimeout )
				{
					// 超时后，重新获得锁, 然后返回; 所以这里要先解锁，否则会导致死锁
					this->mutex.unlock();
					return false;
				}
			}
			val = this->que.front();
			this->que.pop_front();
			this->mutex.unlock();
			this->pushCond.notify();

			return true;
		}

		void remove(const T &val)
		{
			MutexGuard lock( &(this->mutex) );
			this->que.remove( val );
		}

		bool empty()
		{
			MutexGuard lock( &(this->mutex) );
			return this->que.empty();
		}

		size_t size()
		{
			MutexGuard lock( &(this->mutex) );
			return this->que.size();
		}
	
	private:
		Queue(const Queue &);
		Queue &operator=(const Queue &);

		list<T> que;
		size_t maxSize;				// 等于0，表示无队列长度限制
		Mutex mutex;
		Condition pushCond;
		Condition popCond;
};

}

#endif // __OPS_Queue_H
