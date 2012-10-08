#include "ky_log.h"
#include "ops_database.h"

using OPS::Database;


bool Database::isDebug = true;                   ///< 如果设置为true, 则会打印每句执行的SQL语句; 默认为true

Database::~Database()
{
}

void Database::markSql(const char *sql)
{
	KY_LOG_INFO("Database#sql: %s", sql);
}

bool Database::getIsDebug()
{
	return Database::isDebug;
}

void Database::setIsDebug(bool isDebug)
{
	Database::isDebug = isDebug;
}

