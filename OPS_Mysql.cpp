//===============================================
/**
 *  @file OPS_Mysql.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:07
 *  Last   modified:  2012-10-25 09:37:16
 *
 *  Description: 
 */
//================================================

#include <string>
#include "ky_log.h"
#include "OPS_algorithm.h"
#include "OPS_Mysql.h"
#include "OPS_IDbResult.h"

namespace OPS
{

Mysql::Mysql(unsigned int timeout)
{
	my_bool reconnect = 1;

	this->db = mysql_init( NULL );
	if ( this->db == NULL )
	{
		KY_LOG_ERROR("mysql#unable to allocate database connection state");
		return;
	}
	this->setOption( MYSQL_OPT_CONNECT_TIMEOUT, (char *)&timeout );	// 设置 timeout 秒连接超时
	this->setOption( MYSQL_OPT_RECONNECT, (char *)&reconnect );		// 设置重连
	//this->setOption( MYSQL_READ_DEFAULT_GROUP, "your_prog_name");	// MySQL 将读取my.cnf文件的[client]和[your_prog_name]部分配置
	//if ( mysql_set_character_set(this->db, "UTF-8") != 0 )			// 设置字符集
	//{
	//	this->markLastError();
	//}
}

Mysql::~Mysql()
{
	// 清除结果集
	this->dbResult.clearResult();
	if ( this->db != NULL )
	{
		// 关闭数据库连接
		mysql_close( this->db );
	}
}

bool Mysql::setOption(enum mysql_option option, const char *arg)
{
	if ( mysql_options( this->db, option, arg) == 0 )
	{
		return true;
	}
	else
	{
		this->markLastError();
		return false;
	}
}

bool Mysql::connect(string dbname, string host, unsigned int port, string user, string pwd)
{
	if ( mysql_real_connect( this->db, host.c_str(), user.c_str(), pwd.c_str(), dbname.c_str(), port, 0, 0 ) != NULL )
	{
		this->setDbName( dbname );
		return true;
	}
	else
	{
		this->markLastError();
		return false;
	}
}

bool Mysql::execute(const char *sql)
{
	if ( IDatabase::getIsShowSql() )
	{
		this->markSql( sql );
	}

	if ( mysql_real_query( this->db , sql, strlen(sql) ) == 0 )
	{
		return true;
	}
	else
	{
		this->markLastError();
		return false;
	}
}

unsigned long Mysql::executeId(const char *sql)
{
	if ( this->execute(sql) )
	{
		return mysql_insert_id( this->db );
	}
	else
	{
		return 0;
	}
}

bool Mysql::select(const char *sql)
{
	if ( this->execute(sql) == false )
	{
		return false;
	}

	this->dbResult.clearResult();
	return this->saveSelectResult( &(this->dbResult) );
}

IDbResult *Mysql::selectResult(const char *sql)
{
	if ( this->execute(sql) == false )
	{
		return NULL;
	}

	MysqlResult *dbRes = new MysqlResult();
	if ( this->saveSelectResult( dbRes ) == true )
	{
		return dbRes;
	}
	else
	{
		delete dbRes;
		return NULL;
	}
}

bool Mysql::next()
{
	return this->dbResult.next();
}

int Mysql::getInt(const char *fieldName)
{
	return this->dbResult.getInt( fieldName );
}

long Mysql::getLong(const char *fieldName)
{
	return this->dbResult.getLong( fieldName );
}

string Mysql::getString(const char *fieldName)
{
	return this->dbResult.getString( fieldName );
}

unsigned long Mysql::getAffectedRows()
{
	return mysql_affected_rows( this->db );
}

// protected

bool Mysql::saveSelectResult(MysqlResult *result)
{
	unsigned int i;
	unsigned int fieldCount;
	MYSQL_FIELD *field;

	// 保存结果集
	result->res = mysql_store_result( this->db );
	if ( result->res == NULL )
	{
		this->markLastError();
		return false;
	}

	// 建立索引
	fieldCount = mysql_num_fields( result->res );
	field = mysql_fetch_fields( result->res );
	for (i=0; i<fieldCount; i++)
	{
		result->fieldMap[ field[i].name ] = i;		
	}

	return true;
}

void Mysql::markLastError()
{
	KY_LOG_ERROR("mysql#errno: %d errstr: %s", mysql_errno(this->db), mysql_error(this->db));
}

}
