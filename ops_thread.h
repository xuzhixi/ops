#ifndef __OPS_THREAD_H
#define __OPS_THREAD_H

namespace OPS
{

class Thread
{
	public:
		virtual ~Thread();
		bool start();
		unsigned long getId();
	
	protected:
		virtual void run() = 0;
	
	private:
		static void *baseRun(void *param);
		pthread_t id;
};

}

#endif // __OPS_THREAD_H
