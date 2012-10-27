//===============================================
/**
 *  @file OPS_ProcessPool.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-27 02:27:25
 *  Last   modified:  2012-10-27 02:43:43
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_PROCESSPOOL_H
#define __OPS_PROCESSPOOL_H


#include <vector>
#include <sys/types.h>

using std::vector;

namespace OPS
{
	class Process;

	class ProcessPool
	{
		public:
			void start(int count, Process *ps=NULL);
			void wait();

		private:
			vector<pid_t> pidVct;
	};
}

#endif // __OPS_PROCESSPOOL_H
