//===============================================
/**
 *  @file OPS_PriorityQueue.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:20
 *  Last   modified:  2012-10-17 08:19:20
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_PRIORITYQUEUE_H
#define __OPS_PRIORITYQUEUE_H

#include <queue>
#include <functional>
#include <vector>
#include "OPS_Mutex.h"
#include "OPS_MutexGuard.h"
#include "OPS_Condition.h"

using std::priority_queue;
using std::less;
using std::vector;
using OPS::Mutex;
using OPS::MutexGuard;
using OPS::Condition;

namespace OPS
{

template<class T, class Compare = less<T> >
class PriorityQueue
{
	public:
		PriorityQueue(size_t maxSize = 0)
		{
			this->maxSize = maxSize;
		}

		void push(const T &val)
		{
			this->mutex.lock();
			while ( this->maxSize != 0 && this->queue.size() == this->maxSize )
			{
				this->pushCond.wait( this->mutex );
			}
			this->queue.push( val );
			this->mutex.unlock();
			this->popCond.notifyAll();
		}
		
		bool push(const T &val, long sec, long nsec = 0)
		{
			bool isTimeout;

			this->mutex.lock();
			while ( this->maxSize != 0 && this->queue.size() == this->maxSize )
			{
				this->pushCond.timeWait( this->mutex, sec, nsec, &isTimeout);
				if ( isTimeout )
				{
					// 超时后，重新获得锁, 然后返回; 所以这里要先解锁，否则会导致死锁
					this->mutex.unlock();
					return false;
				}
			}
			this->queue.push( val );
			this->mutex.unlock();
			this->popCond.notifyAll();

			return true;
		}

		void pop(T &val)
		{
			this->mutex.lock();
			while ( this->queue.size() == 0 )
			{
				this->popCond.wait( this->mutex );
			}
			val = this->queue.top();
			this->queue.pop();
			this->mutex.unlock();
			this->pushCond.notifyAll();
		}

		bool pop(T &val, long sec, long nsec = 0)
		{
			bool isTimeout;

			this->mutex.lock();
			while ( this->queue.size() == 0 )
			{
				this->popCond.timeWait( this->mutex, sec, nsec, &isTimeout );
				if ( isTimeout )
				{
					// 超时后，重新获得锁, 然后返回; 所以这里要先解锁，否则会导致死锁
					this->mutex.unlock();
					return false;
				}
			}
			val = this->queue.top();
			this->queue.pop();
			this->mutex.unlock();
			this->pushCond.notifyAll();

			return true;
		}

		bool empty()
		{
			MutexGuard lock( &(this->mutex) );
			return this->queue.empty();
		}

		size_t size()
		{
			MutexGuard lock( &(this->mutex) );
			return this->queue.size();
		}
	
	private:
		priority_queue<T, vector<T>, Compare> queue;
		size_t maxSize;				// 等于0，表示无队列长度限制
		Mutex mutex;
		Condition pushCond;
		Condition popCond;
};

}

#endif // __OPS_PRIORITYQUEUE_H
