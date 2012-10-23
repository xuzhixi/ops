#include "ky_log.h"
#include "OPS_XmlDocument.h"
#include "OPS_XmlNode.h"

using OPS::XmlDocument;
using OPS::XmlNode;

int main()
{
	XmlDocument doc;

	doc.parse("<?xml version='1.0' encoding='utf-8' ?><command><user>abc</user><pwd>密码</pwd></command>");
	//doc.parse("<command><user>abc</user><pwd>123</pwd></command>");

	//char a[] = "<command><user>abc</user><pwd>123</pwd></command>";
	//doc.parse(a);
	XmlNode command = doc.firstNode("command");
	XmlNode user = command.firstNode("user");
	XmlNode pwd = command.firstNode("pwd");

	KY_LOG_INFO("user: %s pwd: %s", user.text(), pwd.text());
	doc.save("test.xml");
	
	return 0;
}
