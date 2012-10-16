#include "ky_log.h"
#include "OPS_IDatabase.h"

using OPS::IDatabase;


bool IDatabase::isDebug = true;                   ///< 如果设置为true, 则会打印每句执行的SQL语句; 默认为true

IDatabase::~IDatabase()
{
}

void IDatabase::markSql(const char *sql)
{
	KY_LOG_INFO("Database#sql: %s", sql);
}

bool IDatabase::getIsDebug()
{
	return IDatabase::isDebug;
}

void IDatabase::setIsDebug(bool isDebug)
{
	IDatabase::isDebug = isDebug;
}

