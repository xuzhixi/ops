#include <stdio.h>
#include "OPS_Singleton.h"

using OPS::Singleton;

class Test
{
	public:
		Test()
		{
			printf("consturcture\n");
		}
};


int main()
{
	Singleton<Test>::instance();

	return 0;
}
