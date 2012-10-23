//===============================================
/**
 *  @file OPS_DbConnectPool.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-19 17:23:01
 *  Last   modified:  2012-10-23 20:31:02
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_DBCONNECTPOOL_H
#define __OPS_DBCONNECTPOOL_H

#include <map>
#include <string>
#include "OPS_Queue.h"
#include "OPS_Mutex.h"

using std::map;
using std::string;

namespace OPS
{
class IDatabase;

class DbConnectPool
{
	public:
		~DbConnectPool();
		bool load(const char *fileName);				// 载入配置文件
		IDatabase *getConnect(string poolName);			// 获取一个数据库连接
		bool release(IDatabase *&db, string name="");	// 释放一个数据库连接	
		
		static DbConnectPool *getInstance();			// 获取单例
	
	protected:
		bool hasProperty(map<string,string> &pMap, string name);	// pMap中是存在键名name, 是返回true, 否则返回false
		Queue<IDatabase *> *getPoolQueue(string poolName);			// 获取一个连接池队列
		void clear();									// 清除数据库连接池

	private:
		DbConnectPool();
		DbConnectPool(const DbConnectPool &);
		DbConnectPool &operator=(const DbConnectPool &);

		static Mutex mutex;
		static volatile DbConnectPool *instance;

		Mutex dbMapsMutex;
		map<string, Queue<IDatabase *> *> dbMaps;
};

}

#endif // __OPS_DBCONNECTPOOL_H
