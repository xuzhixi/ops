//===============================================
/**
 *  @file OPS_Mysql.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:07
 *  Last   modified:  2012-10-17 08:19:07
 *
 *  Description: 
 */
//================================================

#include <string>
#include <algorithm>
#include "ky_log.h"
#include "OPS_algorithm.h"
#include "OPS_Mysql.h"


using OPS::IDatabase;
using OPS::Mysql;


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
	this->res = NULL;
}

Mysql::~Mysql()
{
	// 清除结果集
	if ( this->res != NULL )
	{
		mysql_free_result( this->res );
	}
	// 关闭数据库连接
	mysql_close( this->db );
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

int Mysql::getFieldIndex(string fieldName)
{
	// 统一转为小写
	std::transform(fieldName.begin(), fieldName.end(), fieldName.begin(), std::tolower);
	if ( this->fieldMap.find(fieldName) != this->fieldMap.end() )
	{
		return this->fieldMap[ fieldName ];
	}
	else
	{
		KY_LOG_WARN("mysql#can not found fieldName: %s", fieldName.c_str());
		return -1;
	}
}

bool Mysql::connect(const char *host, unsigned int port, const char *user, const char *pwd, const char *dbname)
{
	if ( mysql_real_connect( this->db, host, user, pwd, dbname, port, 0, 0 ) != NULL )
	{
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
	if ( IDatabase::getIsDebug() )
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
	unsigned int i;
	unsigned int fieldCount;
	MYSQL_FIELD *field;

	if ( this->execute(sql) == false )
	{
		return false;
	}

	// 如果结果集不为空，则先将其清空
	if ( this->res != NULL )
	{
		mysql_free_result( this->res );
	}
	// 保存新的结果集
	this->res = mysql_store_result( this->db );

	this->fieldMap.clear();
	// 建立索引
	fieldCount = mysql_num_fields( this->res );
	field = mysql_fetch_fields( this->res );
	for (i=0; i<fieldCount; i++)
	{
		this->fieldMap[ field[i].name ] = i;		
	}

	return true;
}

bool Mysql::next()
{
	if ( this->res != NULL )		// 如果存在结果集
	{
		this->row = mysql_fetch_row( this->res );
		if ( this->row != NULL )	// 如果存在数据记录
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	KY_LOG_WARN("mysql#res collection is NULL");
	return false;
}

int Mysql::getInt(const char *fieldName)
{
	int index;
	int value = -1;

	index = this->getFieldIndex( fieldName );
	if ( index != -1 )		// 如果找到索引
	{
		if ( this->row[index] != NULL )		// 索引对应的值不为NULL
		{
			value = atoi( this->row[index] );
		}
		else
		{
			value = 0;
		}
	}

	return value;
}

long Mysql::getLong(const char *fieldName)
{
	int index;
	long value = -1;

	index = this->getFieldIndex( fieldName );
	if ( index != -1 )		// 如果找到索引
	{
		if ( this->row[index] != NULL )		// 索引对应的值不为NULL
		{
			value = atol( this->row[index] );
		}
		else
		{
			value = 0;
		}
	}

	return value;
}

string Mysql::getString(const char *fieldName)
{
	int index;

	index = this->getFieldIndex( fieldName );
	if ( index != -1 )		// 如果找到索引
	{
		if ( this->row[index] != NULL )		// 索引对应的值不为NULL
		{
			return string( this->row[index] );
		}
		else
		{
			return string("NULL");
		}
	}

	return string("ERROR");
}

unsigned long Mysql::getAffectedRows()
{
	return mysql_affected_rows( this->db );
}

// protected

void Mysql::markLastError()
{
	KY_LOG_ERROR("mysql#errno: %d errstr: %s", mysql_errno(this->db), mysql_error(this->db));
}

