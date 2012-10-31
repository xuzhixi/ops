//===============================================
/**
 *  @file OPS_MultiProcess.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 03:38:26
 *  Last   modified:  2012-10-30 03:50:48
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_MULTIPROCESS_H
#define __OPS_MULTIPROCESS_H

#include <vector>

using std::vector;

namespace OPS
{
	class IProcess;

	class MultiProcess
	{
		public:
			void start(int count, IProcess *ps=NULL);
			void wait();

		private:
			vector<pid_t> pidVct;
	};
}

#endif // __OPS_MULTIPROCESS_H

