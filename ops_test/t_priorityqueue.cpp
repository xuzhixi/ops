#include <unistd.h>
#include "ky_log.h"
#include "ky_tool.h"
#include "ops_priorityqueue.h"
#include "ops_thread.h"

using OPS::PriorityQueue;
using OPS::Thread;

class Producer : public Thread
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
				value = ky_rand(1, 100);
				this->queue->push( value, 0, 1000 * 1000 * 100 );
				printf("producer value: %d total: %d\n", value, this->queue->size());
				usleep( 100 * 1000 );
			}
		}

	private:
		PriorityQueue<int> *queue;
};

class Consumer : public Thread
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
				sleep( 1 );
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
	sleep(50);
	printf("test start\n");
	ky_log_close_default();
	printf("test end\n");

	return 0;
}
