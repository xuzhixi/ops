#include <stdio.h>
#include "OPS_Queue.h"

using OPS::Queue;

int main()
{
	Queue<int *> que;	
	int a[10];
	
	for (int i=0; i<10; i++)
	{
		a[i] = i;
		que.push( a+i );
	}

	int *value;
	while ( !que.empty() )
	{
		que.pop( value );
		printf("%d\n", *value);
	}

	return 0;
}
