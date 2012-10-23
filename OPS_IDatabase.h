//===============================================
/**
 *  @file OPS_IDatabase.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:46
 *  Last   modified:  2012-10-23 19:19:50
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_IDATABASE_H
#define __OPS_IDATABASE_H

#include <string>

using std::string;

namespace OPS 
{
class IDbResult;

class IDatabase
{
	public:
		virtual ~IDatabase();
		string getDbName();
		void setDbName(string dbname);
		virtual bool connect(string dbname, string host, unsigned int port, string user, string pwd) = 0;
		virtual bool execute(const char *sql) = 0;
		virtual unsigned long executeId(const char *sql) = 0;
		virtual bool select(const char *sql) = 0;
		virtual IDbResult *selectResult(const char *sql) = 0;
		virtual bool next() = 0;
		virtual int  getInt(const char *fieldName) = 0;
		virtual long getLong(const char *fieldName) = 0;
		virtual string getString(const char *fieldName) = 0;
		virtual unsigned long getAffectedRows() = 0;

		static bool getIsShowSql();
		static void setIsShowSql(bool isshow);
	
	protected:
		virtual void markLastError() = 0;
		void markSql(const char *sql);

	private:
		static bool isShow;                   ///< 如果设置为true, 则会打印每句执行的SQL语句
		string dbName;
};

}

#endif // __OPS_IDATABASE_H
