//===============================================
/**
 *  @file OPS_Semaphore.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:38
 *  Last   modified:  2012-10-17 08:19:38
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_SEMAPHORE_H
#define __OPS_SEMAPHORE_H

#include <semaphore.h>

namespace OPS
{

class Semaphore
{
	public:
		Semaphore(unsigned int value);
		~Semaphore();
		/// 添加一个资源
		bool post();
		/// 释放一个资源，如果没有可用的资源则会阻塞
		bool release();
		/// 尝试释放一个资源
		bool tryRelease();
		/// 获取现有的资源总数，存在val变量中
		bool getValue(int &val);
	
	private:
		Semaphore(const Semaphore &);
		Semaphore &operator=(const Semaphore &);
		sem_t sem;
};

}

#endif // __OPS_SEMAPHORE_H
