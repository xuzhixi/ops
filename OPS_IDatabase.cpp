//===============================================
/**
 *  @file OPS_IDatabase.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:18:47
 *  Last   modified:  2012-10-23 19:19:49
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_IDatabase.h"

namespace OPS
{

bool IDatabase::isShow = true;                   ///< 如果设置为true, 则会打印每句执行的SQL语句; 默认为true

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

bool IDatabase::getIsShowSql()
{
	return IDatabase::isShow;
}

void IDatabase::setIsShowSql(bool isShow)
{
	IDatabase::isShow = isShow;
}

}
