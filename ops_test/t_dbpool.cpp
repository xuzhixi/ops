//===============================================
/**
 *  @file t_dbpool.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 19:13:06
 *  Last   modified:  2012-10-23 20:31:38
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_IDatabase.h"
#include "OPS_DbConnectPool.h"

using OPS::DbConnectPool;
using OPS::IDatabase;

int main()
{
	IDatabase *db;

	// 初始化数据库连接池
	DbConnectPool::getInstance()->load("config.xml");

	KY_LOG_INFO("第一次获取test数据库连接");
	db = DbConnectPool::getInstance()->getConnect("test");	
	KY_LOG_INFO("释放数据库连接");
	DbConnectPool::getInstance()->release(db);
	KY_LOG_INFO("第二次获取test数据库连接");
	db = DbConnectPool::getInstance()->getConnect("test");	
	KY_LOG_INFO("开始数据库操作");
	if ( db->select("select id,name,age from user") )
	{
		KY_LOG_INFO("affected rows: %ld", db->getAffectedRows());
		while ( db->next() )
		{
			int id;
			long age;
			string name;

			id = db->getInt("id");
			age = db->getLong("age");
			name = db->getString("Name");
			KY_LOG_INFO("id: %d name: %s age: %ld", id, name.c_str(), age);	
		}
	}
	KY_LOG_INFO("释放数据库连接");
	DbConnectPool::getInstance()->release(db);

	return 0;
}
