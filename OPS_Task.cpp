//===============================================
/**
 *  @file OPS_Task.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:56
 *  Last   modified:  2012-10-17 08:19:56
 *
 *  Description: 
 */
//================================================

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
