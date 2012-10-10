#include <unistd.h>
#include <string>
#include "ky_log.h"
#include "ops_thread.h"
#include "ops_mutex.h"
#include "ops_mutexguard.h"

using std::string;
using OPS::Thread;
using OPS::Mutex;
using OPS::MutexGuard;

Mutex g_mutex;

class TestThread : public Thread
{
	public:
		void setName(string name)
		{
			this->name = name;
		}

	protected:
		void run()
		{
			int num = 0;

			MutexGuard gl(&g_mutex);
			while (1)
			{
				num++;
				printf("name: %s threadId: %lu\n", this->name.c_str(), this->getId());
				sleep(1);
				if ( num == 5 )
				{
					break;
				}
			}
		}
	
	private:
		string name;
};

int main()
{
	TestThread t;

	ky_log_open_default("stdout", "a", KY_LOG_LEVEL_ALL, 0, 0);
	t.setName("xiaoming");
	t.start();

	sleep(1);
	MutexGuard gl(&g_mutex);
	printf("main function\n");
	ky_log_close_default();

	return 0;
}
