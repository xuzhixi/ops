//===============================================
/**
 *  @file OPS_Tool.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:20:23
 *  Last   modified:  2012-10-30 03:50:06
 *
 *  Description: 
 */
//================================================

#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "ky_log.h"
#include "OPS_IProcess.h"
#include "OPS_Tool.h"

namespace OPS
{

Mutex Tool::randMutex;

unsigned int Tool::rand(unsigned int start, unsigned int end)
{
	static time_t lastTime = 0;
	unsigned int scopeLen;
	unsigned int result;

	scopeLen = end - start + 1;
	Tool::randMutex.lock();
	if ( lastTime != time(NULL) )
	{
		lastTime = time(NULL);
		srand( lastTime + IProcess::currentPid() );
	}
	result = ( ::rand() % scopeLen  ) + start;
	Tool::randMutex.unlock();

	return result;
}

void *Tool::memzero(void *s, size_t n)
{
	return memset(s, 0, n);
}

bool Tool::savePidFile(const char *fileName)
{
	FILE *fp;

	if ( (fp=fopen(fileName, "w")) == NULL )
	{
		KY_LOG_WARN("open pidfile: %s error!", fileName);
		return false;
	}
	fprintf(fp, "%d\n",  IProcess::currentPid());
	fclose(fp);

	return true;
}

}
