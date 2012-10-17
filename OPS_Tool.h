//===============================================
/**
 *  @file OPS_Tool.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:23
 *  Last   modified:  2012-10-17 08:20:23
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_TOOL_H
#define __OPS_TOOL_H

#include "OPS_Mutex.h"

namespace OPS
{

class Tool
{
	public:
		static unsigned int rand(unsigned int start, unsigned int end);
		static void *memzero(void *s, size_t n);
		static bool savePidFile(const char *fileName);

	private:
		static Mutex randMutex;
};

}

#endif // __OPS_TOOL_H



