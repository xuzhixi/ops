#include <stdio.h>
#include "ops_mutex.h"
#include "ops_condition.h"

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
