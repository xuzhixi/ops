//===============================================
/**
 *  @file OPS_MysqlResult.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-19 15:47:30
 *  Last   modified:  2012-10-20 10:28:29
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_MYSQLRESULT_H
#define __OPS_MYSQLRESULT_H

#include <map>
#include <mysql/mysql.h>
#include "OPS_IDbResult.h"

using std::map;
using std::string;

namespace OPS
{

class MysqlResult : public IDbResult
{
	friend class Mysql;

	public:
		MysqlResult();
		~MysqlResult();
		bool next();
		int  getInt(const char *fieldName);
		long getLong(const char *fieldName);
		string getString(const char *fieldName);

	protected:
		void clearResult();
		int getFieldIndex(string fieldName);

	private:
		MYSQL_RES *res;                 ///< 保存查询的结果集
		map<string, int> fieldMap;      ///< 保存字段与索引的映射对
		MYSQL_ROW row;                  ///< 保存一行数据
};

}

#endif // __OPS_MYSQLRESULT_H
