#include <iostream>  
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"

using namespace rapidxml;  

int main()  
{      
	xml_document<>   doc;      
	file<> fdoc("config.xml");  
	doc.parse<0>(fdoc.data());   

	std::cout<<doc.name()<<std::endl;  

	//! 获取根节点  
	xml_node<>* root = doc.first_node();  
	std::cout<<root->name()<<std::endl;  

	//! 获取根节点第一个节点  
	xml_node<>* node1 = root->first_node();  
	std::cout<<node1->name()<<std::endl;   

	xml_node<>* node11 = node1->first_node();  
	std::cout<<node11->name()<<std::endl;  
	std::cout<<node11->value()<<std::endl;  

	//! 修改之后再次保存  
	xml_node<>* size = root->first_node("size");  
	xml_node<>* w = size->first_node("w");
	xml_node<>* h = size->first_node("h");
	size->remove_node(w);
	size->remove_node(h);
	size->append_node(doc.allocate_node(node_element,"w","2"));  
	size->append_node(doc.allocate_node(node_element,"h","3"));  

	std::string text;    
	rapidxml::print(std::back_inserter(text),doc,0);    

	std::cout<<text<<std::endl;   

	std::ofstream out("config.xml");  
	out << doc;  

	return EXIT_SUCCESS;  
}  

