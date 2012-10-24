#include <stdio.h>
#include <iostream>
#include <ky_log.h>
#include "OPS_Mysql.h"

using namespace OPS;

int main()
{
	Mysql my;
	IDatabase *db = &my;		

	if ( db->connect("test", "192.168.136.1", 3306, "root", "2185530") )
	{
		//printf("autoId: %d\n", db->executeId("insert into user(name, age) values('ktv', 25)"));
		//db->execute("update user set name='xiaoming', age=7 where id=23");
		db->execute("delete from user where id=22");
		printf("affected rows: %ld\n", db->getAffectedRows());
		//if ( db->select("select id,name,age from user where id=30") )
		if ( db->select("select id,name,age from user") )
		{
			printf("affected rows: %ld\n", db->getAffectedRows());
			while ( db->next() )
			{
				int id;
				long age;
				string name;

				id = db->getInt("id");
				age = db->getLong("age");
				name = db->getString("Name");
				printf("id: %d name: %s age: %ld\n", id, name.c_str(), age);	
			}
		}
	}

	return 0;
}
