#include <stdio.h>
#include <iostream>
#include <ky_log.h>
#include <OPS_Mysql.h>

using namespace OPS;

int main()
{
	Mysql my(5);
	Database *db = &my;		

	ky_log_open_default("stdout", "a", KY_LOG_LEVEL_ALL, 0);
	if ( db->connect("192.168.203.1", 3306, "root", "2185530", "test") )
	{
		printf("autoId: %d\n", db->executeId("insert into user(name, age) values('ktv', 25)"));
		printf("affected rows: %ld\n", db->getAffectedRows());
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
	ky_log_close_default();

	return 0;
}
