//===============================================
/**
 *  @file OPS_DbConnectPool.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-19 17:23:01
 *  Last   modified:  2012-10-19 17:34:27
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_DBCONNECTPOOL_H
#define __OPS_DBCONNECTPOOL_H

#include <map>
#include <string>
//#include "OPS_Queue.h"

using std::map;
using std::string;

namespace OPS
{
class IDatabase;

class DbConnectPool
{
	public:
		//bool loadConfig(string fileName);		// 载入配置文件
		//IDatabase *getConnect(string dbName);	// 获取一个数据库连接
		//void release(IDatabase *db);			// 释放一个数据库连接	
	
	private:
		//map<string, Queue<IDatabase *> > dbMaps;
};

}

#endif // __OPS_DBCONNECTPOOL_H
