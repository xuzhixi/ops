//===============================================
/**
 *  @file OPS_DbConnectPool.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-19 17:23:03
 *  Last   modified:  2012-10-24 15:43:05
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
#include "OPS_String.h"
#include "OPS_Mysql.h"

namespace OPS
{

	Mutex DbConnectPool::mutex;
	volatile DbConnectPool *DbConnectPool::instance = NULL;

	DbConnectPool::DbConnectPool()
	{
	}

	DbConnectPool::~DbConnectPool()
	{
		this->clear();
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
				configMap[name][ String::toLower(pProperty["name"]) ] = String::toLower(pProperty["value"]);
				pProperty = pProperty.nextSibling("property");
			}
			pool = pool.nextSibling("pool");
		}

		// 初始化数据库连接池
		IDatabase::setIsShowSql( showSql );

		map<string, map<string,string> >::iterator iter = configMap.begin();
		for ( ; iter != configMap.end(); iter++ )
		{
			string name = iter->first;
			if ( hasProperty(iter->second, "dbtype") )
			{
				if ( iter->second["dbtype"] == "mysql" )
				{
					if ( hasProperty(iter->second, "dbname") && hasProperty(iter->second, "host")
							&&hasProperty(iter->second, "port") && hasProperty(iter->second, "username")
							&&hasProperty(iter->second, "password") && hasProperty(iter->second, "size") )
					{
						int size = String::toInt( iter->second["size"] );
						IDatabase *db;

						if ( size > 0 )
						{
							this->dbMaps[name] = new Queue<IDatabase *>();
							for (int i=0; i<size; i++)
							{
								db = new Mysql();
								int port = String::toInt( iter->second["port"] );
								db->connect(iter->second["dbname"], iter->second["host"], port, iter->second["username"], iter->second["password"]);
								this->dbMaps[name]->push( db );
							}
						}
					}
					else
					{
						KY_LOG_ERROR("please check you dbconnectpool(%s) config!");
						return false;
					}
				}
			}
			else
			{
				KY_LOG_WARN("dbconnectpool(%s) is not config dbtype!", name.c_str());
				return false;
			}
		}

		return true;
	}

	IDatabase *DbConnectPool::getConnect(string poolName)
	{
		Queue<IDatabase *> *que = NULL;

		que = this->getPoolQueue( poolName );
		if ( que != NULL )
		{
			IDatabase *db = NULL;
			que->pop( db );
			return db;
		}
		else
		{
			return NULL;
		}
	}

	bool DbConnectPool::release(IDatabase *&db, string name)
	{
		Queue<IDatabase *> *que = NULL;
		string poolName;

		if ( !name.empty() )
		{
			poolName = name;
		}
		else
		{
			poolName = db->getDbName();
		}

		que = this->getPoolQueue( poolName );
		if ( que != NULL )
		{
			que->push( db );
			db = NULL;
			return true;
		}
		else
		{
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

	// protected
	bool DbConnectPool::hasProperty(map<string,string> &pMap, string name)
	{
		if ( pMap.find(name) == pMap.end() )
		{
			return false;
		}

		return true;
	}

	Queue<IDatabase *> *DbConnectPool::getPoolQueue(string poolName)
	{
			MutexGuard md( &(this->dbMapsMutex) );
			if ( this->dbMaps.find(poolName) != this->dbMaps.end() )
			{
				return this->dbMaps[poolName];
			}
			else
			{
				KY_LOG_WARN("release database connect fail, poolName(%s)", poolName.c_str());
				return NULL;
			}
	}

	void DbConnectPool::clear()
	{
		map<string, Queue<IDatabase *> *>::iterator iter;
		Queue<IDatabase *> *que;	
		IDatabase *db;

		for (iter=this->dbMaps.begin(); iter!=this->dbMaps.end(); iter++)
		{
			// 删除连接池队列
			que = iter->second;	
			while ( !que->empty() )
			{
				que->pop( db );
				delete db;
			}
			delete que;
		}
		this->dbMaps.clear();
	}

}
