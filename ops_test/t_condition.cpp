#include <stdio.h>
#include "OPS_Mutex.h"
#include "OPS_Condition.h"

using OPS::Mutex;
using OPS::Condition;

int main()
{
	Mutex mutex;
	Condition cond;

	printf("start\n");
	cond.wait( mutex );
	printf("end\n");

	return 0;
}
