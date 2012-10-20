//===============================================
/**
 *  @file OPS_DbConnectPool.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-19 17:23:03
 *  Last   modified:  2012-10-20 15:14:41
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_DbConnectPool.h"
#include "OPS_IDatabase.h"
#include "OPS_MutexGuard.h"

namespace OPS
{

Mutex DbConnectPool::mutex;
volatile DbConnectPool *DbConnectPool::instance = NULL;

DbConnectPool::DbConnectPool()
{
}

DbConnectPool::~DbConnectPool()
{
}

bool DbConnectPool::loadConfig(string fileName)
{
	fileName = "abc";
	return true;
}

bool DbConnectPool::reloadCofig(string fileName)
{
	fileName = "abc";
	return true;
}

IDatabase *DbConnectPool::getConnect(string dbName)
{
	if ( this->dbMaps.find(dbName) != this->dbMaps.end() )
	{
		IDatabase *db = NULL;
		this->dbMaps[dbName]->pop( db );
		return db;
	}
	else
	{
		KY_LOG_WARN("get database connect fail, dbName(%s)", dbName.c_str());
		return NULL;
	}
}

bool DbConnectPool::release(IDatabase *&db)
{
	string dbName = db->getDbName();

	if ( this->dbMaps.find(dbName) != this->dbMaps.end() )
	{
		this->dbMaps[dbName]->push( db );
		db = NULL;
		return true;
	}
	else
	{
		KY_LOG_WARN("release database connect fail, dbName(%s)", dbName.c_str());
		return false;
	}
}

DbConnectPool *DbConnectPool::getInstance()
{
	// 使用双重检查加锁, 避免不必要的同步操作
	if ( DbConnectPool::instance == NULL )
	{
		MutexGuard mg( &(DbConnectPool::mutex) );
		if ( DbConnectPool::instance == NULL )
		{
			DbConnectPool::instance = new DbConnectPool();
		}
	}
	
	return (DbConnectPool *)DbConnectPool::instance;
}

}
