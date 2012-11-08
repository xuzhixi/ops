//===============================================
/**
 *  @file t_shareptr.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-11-03 13:35:34
 *  Last   modified:  2012-11-03 13:37:11
 *
 *  Description: 
 */
//================================================

#include <stdio.h>
#include <string>
#include "OPS_SharePtr.h"
#include "OPS_NoMutex.h"

using std::string;
using OPS::SharePtr;
using OPS::NoMutex;

class Test
{
	public:
		Test(string name)
		{
			this->name = name;
		}

		~Test()
		{
			printf("delete name: %s\n", name.c_str());
		}

		void setName(string name)
		{
			this->name = name;
		}

		string getName()
		{
			return this->name;
		}
		
	private:
		string name;
};

void test_func(SharePtr<Test> obj)
{
}

int main()
{
	SharePtr<Test> a = new Test("xiaoming");
	SharePtr<Test> b;
	b = a;
	SharePtr<Test> c = new Test("xiaobai");

	a = b;
	test_func( a );
	printf("before name: %s\n", a->getName().c_str());	
	a->setName("abc");
	printf("after name: %s\n", a->getName().c_str());	
	
	if ( a == c )
	{
		printf("a equals c\n");
	}
	else
	{
		printf("a not equals c\n");
	}

	return 0;	
}
