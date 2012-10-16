#ifndef __OPS_IDATABASE_H
#define __OPS_IDATABASE_H

#include <string>

using std::string;

namespace OPS 
{

class IDatabase
{
	public:
		virtual ~IDatabase();
		virtual bool connect(const char *host, unsigned int port, const char *user, const char *pwd, const char *dbname) = 0;
		virtual bool execute(const char *sql) = 0;
		virtual unsigned long executeId(const char *sql) = 0;
		virtual bool select(const char *sql) = 0;
		virtual bool next() = 0;
		virtual int  getInt(const char *fieldName) = 0;
		virtual long getLong(const char *fieldName) = 0;
		virtual string getString(const char *fieldName) = 0;
		virtual unsigned long getAffectedRows() = 0;

		static bool getIsDebug();
		static void setIsDebug(bool isDebug);
	
	protected:
		virtual void markLastError() = 0;
		void markSql(const char *sql);

	private:
		static bool isDebug;                   ///< 如果设置为true, 则会打印每句执行的SQL语句
};

}

#endif // __OPS_IDATABASE_H
