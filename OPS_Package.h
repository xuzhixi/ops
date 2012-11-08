//===============================================
/**
 *  @file OPS_Package.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-06 23:40:14
 *  Last   modified:  2012-11-06 23:40:14
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_PACKAGE_H
#define __OPS_PACKAGE_H

#include <sys/types.h>

namespace OPS
{
	class Package
	{
		friend class TcpSocket;

		public:
			Package(char *data, size_t dataLen);
			~Package();

		private:
			char *data;
			size_t len;
	};
}

#endif // __OPS_PACKAGE_H
