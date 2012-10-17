//===============================================
/**
 *  @file OPS_Mysql.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:07
 *  Last   modified:  2012-10-17 08:19:07
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_MYSQL_H
#define __OPS_MYSQL_H

#include <map>
#include <string>
#include <mysql/mysql.h>
#include "OPS_IDatabase.h"

using std::map;
using std::string;

namespace OPS
{

class Mysql : public IDatabase
{
	public:
		Mysql(unsigned int timeout);
		~Mysql();
		bool setOption(enum mysql_option option, const char *arg);
		bool connect(const char *host, unsigned int port, const char *user, const char *pwd, const char *dbname);
		bool execute(const char *sql);
		unsigned long executeId(const char *sql);
		bool select(const char *sql);
		bool next();
		int  getInt(const char *fieldName);
		long getLong(const char *fieldName);
		string getString(const char *fieldName);
		unsigned long getAffectedRows();

	protected:
		int getFieldIndex(string fieldName);
		void markLastError();

	private:
		MYSQL *db;                      ///< 数据库连接
		MYSQL_RES *res;                 ///< 保存查询的结果集
		map<string, int> fieldMap;      ///< 保存字段与索引的映射对
		MYSQL_ROW row;                  ///< 保存一行数据
};

}

#endif // __OPS_MYSQL_H
