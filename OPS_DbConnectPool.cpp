//===============================================
/**
 *  @file OPS_DbConnectPool.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-19 17:23:03
 *  Last   modified:  2012-10-22 18:45:39
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_DbConnectPool.h"
#include "OPS_IDatabase.h"
#include "OPS_MutexGuard.h"
#include "OPS_XmlDocument.h"
#include "OPS_XmlNode.h"

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

bool DbConnectPool::load(const char *fileName)
{
	map<string, string> gMap;
	map<string, map<string, string> > configMap;
	bool showSql = false;
	XmlDocument doc(fileName);
	
	XmlNode connect = doc.firstNode("connect");

	// 获取全局属性
	XmlNode gProperty = connect.firstNode("property");
	while ( !gProperty.isNull() )
	{
		gMap[ gProperty["name"] ] = gProperty["value"];
		gProperty = gProperty.nextSibling("property");
	}	
	if ( gMap.find("show_sql") != gMap.end() && gMap["show_sql"] == "true" )
	{
		showSql = true;
	}

	// 获取各个连接池的属性
	XmlNode pool = connect.firstNode("pool");
	while( !pool.isNull() )
	{		
		string name = pool["name"];
		XmlNode pProperty = pool.firstNode("property");
		while ( !pProperty.isNull() )
		{
			configMap[name][ pProperty["name"] ] = pProperty["value"];
			pProperty = pProperty.nextSibling("property");
		}
		pool = pool.nextSibling("pool");
	}

	map<string, map<string,string> >::iterator iters = configMap.begin();
	for ( ; iters != configMap.end(); iters++ )
	{
		string name = iters->first;
		map<string, string>::iterator iter = iters->second.begin();
		KY_LOG_INFO("name: %s", name.c_str());
	}

	return true;
}

bool DbConnectPool::reload(const char *fileName)
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
