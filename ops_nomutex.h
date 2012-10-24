//===============================================
/**
 *  @file OPS_NoMutex.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-22 23:04:30
 *  Last   modified:  2012-10-22 23:05:58
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_NOMUTEX_H
#define __OPS_NOMUTEX_H

namespace OPS
{

class NoMutex
{
	friend class Condition;

	public:
		NoMutex();
		~NoMutex();
		bool lock();
		bool trylock();
		bool unlock();
	
	private:
		NoMutex(const NoMutex &);
		NoMutex &operator=(const NoMutex &);
};

}
#endif // __OPS_NOMUTEX_H
