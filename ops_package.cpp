//===============================================
/**
 *  @file OPS_Package.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-06 23:40:17
 *  Last   modified:  2012-11-06 23:40:17
 *
 *  Description: 
 */
//================================================

#include <stdlib.h>
#include "OPS_Package.h"

namespace OPS
{
	Package::Package(char *data, size_t dataLen)
	{
		this->data = data;
		this->len = dataLen;
	}

	Package::~Package()
	{
		if ( data != NULL )
		{
			free( data );
		}
	}
}
