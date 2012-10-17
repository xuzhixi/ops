//===============================================
/**
 *  @file OPS_Task.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:55
 *  Last   modified:  2012-10-17 08:19:55
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_TASK_H
#define __OPS_TASK_H

namespace OPS
{

class Task
{
	public:
		Task(int level=0);
		virtual ~Task();
		virtual bool execute();
		int getLevel() const;
		void setLevel(int level);
		bool operator()(Task *&t1, Task *&t2) const;
	
	private:
		int level;
};

}

#endif // __OPS_TASK_H
