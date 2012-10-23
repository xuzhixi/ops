#include "OPS_XmlDocument.h"
#include "OPS_XmlNode.h"

using OPS::XmlDocument;
using OPS::XmlNode;

int main()  
{      
	XmlDocument doc;    

	XmlNode node = doc.allocNode(node_element,"config");    

	XmlNode color = doc.allocNode(node_element,"color");    
	XmlNode red = doc.allocNode(node_element, "red", "0.1");
	color.appendNode(red);  
	red.setLabel("pink");
	red.setText("0.2");
	color.appendNode(node_element,"green","0.1");  
	color.appendNode(node_element,"blue","0.1");  
	color.appendNode(node_element,"alpha","1.0");  

	XmlNode size = doc.allocNode(node_element,"size");   
	size.appendNode(node_element,"x","640");  
	size.appendNode(node_element,"y","480");  
	size.setLabel("Size");
	size.setAttribute("value", "18");

	XmlNode mode = doc.allocNode(node_element,"mode","screen mode");  
	mode.appendAttribute("fullscreen","false");  
	mode.setText("testMode");

	doc.appendNode(node_pi, "xml version='1.0' encoding='utf-8'");  
	node.appendNode(color);  
	node.appendNode(size);  
	node.appendNode(mode);  
	doc.appendNode(node);  
	
	doc.save("config.xml3");

	return EXIT_SUCCESS;  
}  
