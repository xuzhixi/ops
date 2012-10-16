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
