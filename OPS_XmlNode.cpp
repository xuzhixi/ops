//===============================================
/**
 *  @file OPS_XmlNode.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-22 09:33:51
 *  Last   modified:  2012-10-22 22:39:34
 *
 *  Description: 
 */
//================================================

#include "OPS_XmlNode.h"

namespace OPS
{
	XmlNode::XmlNode(xml_document<> *d, xml_node<> *n)
	{
		this->node = n;
		this->doc = d;
	}

	XmlNode XmlNode::firstNode(const char *name, bool caseSensitive)
	{
		return XmlNode( this->doc, this->node->first_node(name, 0, caseSensitive) );	
	}

	XmlNode XmlNode::lastNode(const char *name, bool caseSensitive)
	{
		return XmlNode( this->doc, this->node->last_node(name, 0, caseSensitive) );
	}

	XmlNode XmlNode::preSibling(const char *name, bool caseSensitive)
	{
		return XmlNode( this->doc, this->node->previous_sibling(name, 0, caseSensitive) );
	}

	XmlNode XmlNode::nextSibling(const char *name, bool caseSensitive)
	{
		return XmlNode( this->doc, this->node->next_sibling(name, 0, caseSensitive) );
	}

	void XmlNode::prependNode(XmlNode n)
	{
		this->node->prepend_node( n.node );
	}

	void XmlNode::prependNode(node_type type, const char *name, const char *value)
	{
		char *allocName = this->allocString(name);
		char *allocValue = this->allocString(value);
		xml_node<> *n = this->doc->allocate_node( type, allocName, allocValue );

		this->node->prepend_node( n );
	}

	void XmlNode::appendNode(XmlNode n)
	{
		this->node->append_node( n.node );	
	}

	void XmlNode::appendNode(node_type type, const char *name, const char *value)
	{
		char *allocName = this->allocString(name);
		char *allocValue = this->allocString(value);
		xml_node<> *n = this->doc->allocate_node( type, allocName, allocValue );

		this->node->append_node( n );
	}

	void XmlNode::appendAttribute(const char *name, const char *value)
	{
		char *allocName = this->allocString(name);
		char *allocValue = this->allocString(value);
		xml_attribute<> *attr = this->doc->allocate_attribute( allocName, allocValue );	

		this->node->append_attribute( attr );  
	}

	void XmlNode::removeNode(XmlNode n)
	{
		this->node->remove_node( n.node );
	}

	void XmlNode::removeNode(const char *name, bool caseSensitive)
	{
		xml_node<> *iter = this->node->first_node(name, 0, caseSensitive);
		xml_node<> *delNode;

		while ( iter != NULL )
		{
			delNode = iter;
			iter = iter->next_sibling(name);
			this->node->remove_node( delNode );
		}
	}

	void XmlNode::removeAllNode()
	{
		this->node->remove_all_nodes();
	}

	void XmlNode::removeAttribute(const char *name, bool caseSensitive)
	{
		xml_attribute<> *attr = this->node->first_attribute(name, 0, caseSensitive);
		if ( attr != NULL )
		{
			this->node->remove_attribute( attr );
		}
	}

	void XmlNode::removeAllAttribute()
	{
		this->node->remove_all_attributes();
	}

	bool XmlNode::isNull()
	{
		if ( this->node == NULL )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void XmlNode::setLabel(const char *label)
	{
		char *allocLabel = this->allocString( label );
		this->node->name( allocLabel );
	}

	char *XmlNode::label()
	{
		return this->node->name();
	}

	void XmlNode::setText(const char *text)
	{
		char *allocText = this->allocString( text );
		this->node->value( allocText );
	}

	char *XmlNode::text()
	{
		return this->node->value();
	}

	void XmlNode::setAttribute(const char *name, const char *value, bool caseSensitive)
	{
		xml_attribute<> *attr = this->node->first_attribute( name, 0, caseSensitive );

		if ( attr != NULL )		// 有这个属性，则修改
		{
			char *allocValue = this->allocString( value );
			attr->value( allocValue );
		}
		else	// 没有这个属性，则添加
		{
			this->appendAttribute( name, value );	
		}
	}

	char *XmlNode::attribute(const char *attrName, bool caseSensitive)
	{
		xml_attribute<> *attr = this->node->first_attribute(attrName, 0, caseSensitive);
		if ( attr != NULL )
		{
			return attr->value();
		}
		else
		{
			return NULL;
		}
	}

	char *XmlNode::operator[](const char *attrName)
	{
		return this->attribute( attrName );
	}

	// protected
	char *XmlNode::allocString(const char *s)
	{
		if ( s != NULL )
		{
			return this->doc->allocate_string(s);
		}
		else
		{
			return NULL;
		}
	}

}
