//===============================================
/**
 *  @file OPS_NoMutex.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-22 23:05:02
 *  Last   modified:  2012-10-22 23:06:32
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_NoMutex.h"

namespace OPS
{

NoMutex::NoMutex()
{
}

NoMutex::~NoMutex()
{
}

bool NoMutex::lock()
{
	return true;
}

bool NoMutex::trylock()
{
	return true;
}

bool NoMutex::unlock()
{
	return true;
}

}
