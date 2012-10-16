#include <stdio.h>
#include "ky_log.h"
#include "OPS_Task.h"
#include "OPS_ThreadPool.h"
//#include "OPS_PriorityQueue.h"

using OPS::Task;
using OPS::ThreadPool;
//using OPS::PriorityQueue;

class TestTask : public Task
{
	public:
		TestTask(int level=0)
		{
			this->setLevel( level );
		}

		bool execute()
		{
			printf("task level %d\n",  this->getLevel());
		}
};

int main()
{
	//PriorityQueue<TestTask> queue;
	//TestTask task(10);
	//TestTask task2(8);
	//TestTask task3(9);
	//TestTask task4(11);
	//queue.push( task );
	//queue.push( task2 );
	//queue.push( task3 );
	//queue.push( task4 );
	//while ( !queue.empty() )
	//{
	//	queue.pop(task);
	//	task.execute();
	//}

	ky_log_open_default("stdout", "a", KY_LOG_LEVEL_ALL, 0, 0);
	ThreadPool threadPool(5);
	for (int i=0; i<10; i++)
	{
		Task *task = new TestTask(i);
		threadPool.addTask( task ); 
	}
	printf("start threadpool...\n");
	threadPool.start();
	printf("start successful!\n");
	sleep(1);
	printf("stop threadpoll...\n");
	threadPool.stop();
	printf("stop successful!\n");
	sleep(3);
	ky_log_close_default();

	return 0;
}
