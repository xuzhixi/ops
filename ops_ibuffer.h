//===============================================
/**
 *  @file OPS_IBuffer.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-30 23:34:12
 *  Last   modified:  2012-10-30 23:34:12
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_IBUFFER_H
#define __OPS_IBUFFER_H

namespace OPS
{
	class IBuffer
	{
		public:
			virtual ~IBuffer();
			virtual void append(char *data, int len) = 0;
	};
}

#endif // __OPS_IBUFFER_H
