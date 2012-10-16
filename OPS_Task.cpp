#include "OPS_Task.h"

using OPS::Task;

Task::Task(int level)
{
	this->level = level;
}

Task::~Task()
{
}

bool Task::execute()
{
	return true;
}

int Task::getLevel() const
{
	return this->level;
}

void Task::setLevel(int level)
{
	this->level = level;
}

bool Task::operator()(Task *&t1, Task *&t2) const
{
	if ( t1->getLevel() < t2->getLevel() )
	{
		return true;
	}
	else
	{
		return false;
	}
}
