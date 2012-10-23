#include "OPS_DbConnectPool.h"

using OPS::DbConnectPool;

int main()
{
	DbConnectPool::getInstance()->load("config.xml");

	return 0;
}
