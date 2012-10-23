//===============================================
/**
 *  @file OPS_XmlNode.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-22 09:33:53
 *  Last   modified:  2012-10-22 22:38:57
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_XMLNODE_H
#define __OPS_XMLNODE_H

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"  
#include "rapidxml/rapidxml_print.hpp" 

using namespace rapidxml;

namespace OPS
{

	class XmlNode
	{
		public:
			XmlNode(xml_document<> *d, xml_node<> *n);
			XmlNode firstNode(const char *name=NULL, bool caseSensitive=true);
			XmlNode lastNode(const char *name=NULL, bool caseSensitive=true);
			XmlNode preSibling(const char *name=NULL, bool caseSensitive=true);
			XmlNode nextSibling(const char *name=NULL, bool caseSensitive=true);
			void prependNode(XmlNode n);
			void prependNode(node_type type, const char *name=NULL, const char *value=NULL);
			void appendNode(XmlNode n);
			void appendNode(node_type type, const char *name=NULL, const char *value=NULL);
			void appendAttribute(const char *name=NULL, const char *value=NULL);
			void removeNode(XmlNode n);
			void removeNode(const char *name, bool caseSensitive=true);
			void removeAllNode();
			void removeAttribute(const char *name, bool caseSensitive=true);
			void removeAllAttribute();
			bool isNull();
			void setLabel(const char *label);
			char *label();
			void setText(const char *text);
			char *text();
			void setAttribute(const char *name, const char *value, bool caseSensitive=true);
			char *attribute(const char *attrName, bool caseSensitive=true);
			char *operator[](const char *attrName);

		protected:
			char *allocString(const char *s);

		private:
			xml_node<> *node;			// 当前节点
			xml_document<> *doc;		// 文档节点
	};

}

#endif // __OPS_XMLNODE_H
