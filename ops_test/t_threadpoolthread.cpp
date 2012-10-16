#include <unistd.h>
#include <stdio.h>
#include "OPS_IThread.h"

using OPS::IThread;

template<class T>
class TestPoolThread : public IThread
{
	protected:
		void run()
		{
			printf("test\n");
		}
};

int main()
{
	TestPoolThread<int> tpt;

	tpt.start();
	sleep(1);
	
	return 0;
}
