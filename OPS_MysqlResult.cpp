//===============================================
/**
 *  @file OPS_MysqlResult.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-19 15:47:29
 *  Last   modified:  2012-10-20 10:28:33
 *
 *  Description: 
 */
//================================================

#include <algorithm>
#include "ky_log.h"
#include "OPS_MysqlResult.h"

namespace OPS
{

MysqlResult::MysqlResult()
{
	this->res = NULL;
}

MysqlResult::~MysqlResult()
{
	this->clearResult();	
}

bool MysqlResult::next()
{
	if ( this->res != NULL )		// 如果存在结果集
	{
		this->row = mysql_fetch_row( this->res );
		if ( this->row != NULL )	// 如果存在数据记录
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	KY_LOG_WARN("mysql#res collection is NULL");
	return false;
}

int MysqlResult::getInt(const char *fieldName)
{
	int index;
	int value = -1;

	index = this->getFieldIndex( fieldName );
	if ( index != -1 )		// 如果找到索引
	{
		if ( this->row[index] != NULL )		// 索引对应的值不为NULL
		{
			value = atoi( this->row[index] );
		}
		else
		{
			value = 0;
		}
	}

	return value;
}

long MysqlResult::getLong(const char *fieldName)
{
	int index;
	long value = -1;

	index = this->getFieldIndex( fieldName );
	if ( index != -1 )		// 如果找到索引
	{
		if ( this->row[index] != NULL )		// 索引对应的值不为NULL
		{
			value = atol( this->row[index] );
		}
		else
		{
			value = 0;
		}
	}

	return value;
}

string MysqlResult::getString(const char *fieldName)
{
	int index;

	index = this->getFieldIndex( fieldName );
	if ( index != -1 )		// 如果找到索引
	{
		if ( this->row[index] != NULL )		// 索引对应的值不为NULL
		{
			return string( this->row[index] );
		}
		else
		{
			return string("NULL");
		}
	}

	return string("ERROR");
}

// protected
void MysqlResult::clearResult()
{
	// 清除结果集
	if ( this->res != NULL )
	{
		mysql_free_result( this->res );
		this->res = NULL;
		this->fieldMap.clear();
	}
}

int MysqlResult::getFieldIndex(string fieldName)
{
	// 统一转为小写
	std::transform(fieldName.begin(), fieldName.end(), fieldName.begin(), std::tolower);
	if ( this->fieldMap.find(fieldName) != this->fieldMap.end() )
	{
		return this->fieldMap[ fieldName ];
	}
	else
	{
		KY_LOG_WARN("mysql#can not found fieldName: %s", fieldName.c_str());
		return -1;
	}
}

}
