#include <cstdio>
#include <cstdlib>
#include "OPS_Tool.h"

using OPS::Tool;

int main()
{
	int i;
	int minute;

	//srand( time(NULL) );
	//for (i=0; i<10; i++)
	//{
	//	minute = ( rand() % 9 ) + 1;
	//	printf("minute: %d\n", minute);
	//}
	
	printf("RAND_MAX: %d result: %d\n", RAND_MAX, Tool::rand(1,100));
	printf("RAND_MAX: %d result: %d\n", RAND_MAX, Tool::rand(1,100));
	printf("RAND_MAX: %d result: %d\n", RAND_MAX, Tool::rand(1,100));
	printf("RAND_MAX: %d result: %d\n", RAND_MAX, Tool::rand(1,100));
	printf("RAND_MAX: %d result: %d\n", RAND_MAX, Tool::rand(1,100));

	return 0;
}
