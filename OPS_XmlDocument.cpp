//===============================================
/**
 *  @file OPS_XmlDocument.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-22 09:33:40
 *  Last   modified:  2012-10-22 23:00:23
 *
 *  Description: 
 */
//================================================

#include <fstream>
#include "OPS_XmlDocument.h"

using std::ofstream;

namespace OPS
{

	XmlDocument::XmlDocument() : XmlNode(&doc, &doc)
	{
	}

	XmlDocument::XmlDocument(const char *fileName) : XmlNode(&doc, &doc)
	{
		file<> fdoc( fileName );  
		//doc.parse<0>( fdoc.data() );
		this->parse( fdoc.data() );
	}

	void XmlDocument::parse(const char *text)
	{
		char *allocText = this->allocString( text );
		doc.parse<0>( allocText );
	}

	XmlNode XmlDocument::allocNode(node_type type, const char *name, const char *value)
	{
		char *allocName = this->allocString(name);
		char *allocValue = this->allocString(value);
		xml_node<> *newNode = doc.allocate_node(type, allocName, allocValue);

		return XmlNode( &doc, newNode );
	}

	void XmlDocument::save(const char *fileName)
	{
		ofstream out( fileName );	//ofstream 默认时，如果文件存在则会覆盖原来的内容，不存在则会新建  
		out << doc;					//doc 这样输出时在目标文件中不会有xml 头信息---<?xml version='1.0' encoding='utf-8' >  
		out.close(); 
	}

}
