//===============================================
/**
 *  @file OPS_Process.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:25
 *  Last   modified:  2012-10-17 08:19:25
 *
 *  Description: 
 */
//================================================

#include <unistd.h>
#include "OPS_Process.h"

using OPS::Process;

long Process::currentPid()
{
	return (long)getpid();
}
