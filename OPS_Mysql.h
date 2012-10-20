//===============================================
/**
 *  @file OPS_Mysql.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:07
 *  Last   modified:  2012-10-20 10:38:46
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_MYSQL_H
#define __OPS_MYSQL_H

#include <string>
#include <mysql/mysql.h>
#include "OPS_IDatabase.h"
#include "OPS_MysqlResult.h"

using std::string;

namespace OPS
{
class IDbResult;

class Mysql : public IDatabase
{
	public:
		Mysql(unsigned int timeout = 5);	// 默认5秒连接超时
		~Mysql();
		bool setOption(enum mysql_option option, const char *arg);
		bool connect(const char *host, unsigned int port, const char *user, const char *pwd, const char *dbname);
		bool execute(const char *sql);
		unsigned long executeId(const char *sql);
		bool select(const char *sql);
		IDbResult *selectResult(const char *sql);
		bool next();
		int  getInt(const char *fieldName);
		long getLong(const char *fieldName);
		string getString(const char *fieldName);
		unsigned long getAffectedRows();

	protected:
		bool saveSelectResult(MysqlResult *result);
		void markLastError();

	private:
		MYSQL *db;                      ///< 数据库连接
		MysqlResult dbResult;			///< 保存结果集
};

}

#endif // __OPS_MYSQL_H
