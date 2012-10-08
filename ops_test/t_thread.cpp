#include <unistd.h>
#include <string>
#include "ky_log.h"
#include "ops_thread.h"

using std::string;
using OPS::Thread;

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
			while (1)
			{
				printf("name: %s threadId: %lu\n", this->name.c_str(), this->getId());
				sleep(1);
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
	ky_log_close_default();

	printf("main function\n");
	sleep(5);

	return 0;
}
