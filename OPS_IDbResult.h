//===============================================
/**
 *  @file OPS_IDbResult.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-19 15:43:05
 *  Last   modified:  2012-10-19 15:43:35
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_IDBRESULT_H
#define __OPS_IDBRESULT_H

#include <string>

using std::string;

namespace OPS
{

class IDbResult
{
	public:
		virtual ~IDbResult();
		virtual bool next() = 0;
		virtual int  getInt(const char *fieldName) = 0;
		virtual long getLong(const char *fieldName) = 0;
		virtual string getString(const char *fieldName) = 0;
};

}

#endif // __OPS_IDBRESULT_H
