#include <unistd.h>
#include "ky_log.h"
#include "OPS_Tool.h"
#include "OPS_PriorityQueue.h"
#include "OPS_IThread.h"

using OPS::PriorityQueue;
using OPS::IThread;
using OPS::Tool;

class Producer : public IThread
{
	public:
		Producer(PriorityQueue<int> *q)
		{
			this->queue = q;
		}

	protected:
		void run()
		{
			int value;
			while (1)
			{
				value = Tool::rand(1, 100);
				//this->queue->push( value, 0, 1000 * 1000 * 10 );
				this->queue->push( value, 1 );
				printf("producer value: %d total: %d\n", value, this->queue->size());
				usleep( 100 * 1000 );
			}
		}

	private:
		PriorityQueue<int> *queue;
};

class Consumer : public IThread
{
	public:
		Consumer(PriorityQueue<int> *q)
		{
			this->queue = q;
		}

	protected:
		void run()
		{
			int value;
			while (1)
			{
				this->queue->pop( value );
				printf("consumer value: %d total: %d\n", value, this->queue->size());
				sleep( 2 );
			}
		}

	private:
		PriorityQueue<int> *queue;
};

int main()
{
	PriorityQueue<int> queue(10);
	Producer producer( &queue );
	Consumer consumer( &queue );

	ky_log_open_default("stdout", "a", KY_LOG_LEVEL_ALL, 0, 0);
	producer.start();
	consumer.start();
	sleep(3);
	printf("test start\n");
	ky_log_close_default();
	//int value;
	//queue.pop( value );
	printf("test end\n");

	return 0;
}
