#include <cstdio>
#include "OPS_XmlDocument.h"
#include "OPS_XmlNode.h"

using OPS::XmlDocument;
using OPS::XmlNode;

int main()  
{      
	XmlDocument doc("config.xml");
	// 获取connect节点 
	XmlNode connect = doc.firstNode("connect");  

	// 获取全局属性配置
	XmlNode node = connect.firstNode("property");
	printf("global property:\n");
	for (; !node.isNull(); node = node.nextSibling("property"))
	{
		printf("name: %s value: %s\n", node["name"], node["value"]);
	}

	XmlNode pool = connect.firstNode("pool");
	printf("pools:\n");
	for (; !pool.isNull(); pool = pool.nextSibling("pool"))
	{
		printf("pool:\n");
		printf("name: %s\n", pool["name"]);
		node = pool.firstNode("property");
		for (; !node.isNull(); node = node.nextSibling("property"))
		{
			printf("name: %s value: %s\n", node["name"], node["value"]);
		}
	}

	doc.save("config.xml2");

	return EXIT_SUCCESS;  
}  

