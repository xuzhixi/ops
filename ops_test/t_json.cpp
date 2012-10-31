#include <iostream>
#include <string>
#include "json/json.h"

using namespace std;

int main()
{
	std::string test = "{\"test\":5,\"Value\":{\"版本\":\"this is version中文\"}}";
	Json::Reader reader;
	Json::Value value;
	if(reader.parse(test,value))
	{
		int i = 0;
		bool isNull = value["test"].isNull();
		if(!isNull)                       //测试是否有此项（是否为空）
			i = value["test"].asInt();    //取test值
			cout << "test: " << i << endl;

		if(!value["Value"]["版本"].isNull())
		{
			std::string str = value["Value"]["版本"].asString();   //取version的值
			cout << "version: " << str << endl;
			Json::Value val = value["Value"];                         //第二种方法
			std::string str1 = val["版本"].asString();
			cout << "version1: " << str1 << endl;
		}

		Json::Value val1= value["NoCode"];      //取一个没有的值
		if(!val1.isNull())
		{
			i = val1.asInt();                   //不能到达此处，测试通不过
			cout << "end: " << i << endl;
		}
	}
}
