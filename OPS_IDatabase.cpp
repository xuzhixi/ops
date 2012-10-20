//===============================================
/**
 *  @file OPS_IDatabase.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:47
 *  Last   modified:  2012-10-20 10:39:32
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_IDatabase.h"

namespace OPS
{

bool IDatabase::isDebug = true;                   ///< 如果设置为true, 则会打印每句执行的SQL语句; 默认为true

IDatabase::~IDatabase()
{
}


string IDatabase::getDbName()
{
	return this->dbName;
}

void IDatabase::setDbName(string dbname)
{
	this->dbName = dbname;
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

}
