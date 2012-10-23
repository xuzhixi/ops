//===============================================
/**
 *  @file OPS_XmlDocument.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-22 09:33:20
 *  Last   modified:  2012-10-22 22:51:27
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_XMLDOCUMENT_H
#define __OPS_XMLDOCUMENT_H

#include "OPS_XmlNode.h"

namespace OPS
{

	class XmlDocument : public XmlNode
	{
		public:
			XmlDocument();
			XmlDocument(const char *fileName);
			void parse(const char *text);
			XmlNode allocNode(node_type type, const char *name=NULL, const char *value=NULL);
			void save(const char *fileName);

		private:
			xml_document<> doc;      
	};

}

#endif // __OPS_XMLDOCUMENT_H
