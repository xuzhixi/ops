//===============================================
/**
 *  @file t_ini2.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 14:39:56
 *  Last   modified:  2012-10-23 14:42:26
 *
 *  Description: 
 */
//================================================

#include <list>
#include "ky_log.h"
#include "OPS_ParseIni.h"

using std::list;
using OPS::ParseIni;

int main()
{
	ParseIni parseIni("room.ini");

	list<string> sections;
	sections = parseIni.getAllSections();
	list<string>::iterator i;
	for (i = sections.begin(); i != sections.end(); ++i) 
	{ 
		KY_LOG_INFO("section: %s", i->c_str());
		KY_LOG_INFO("host: %s", parseIni.getValue(i->c_str(), "host"));
		KY_LOG_INFO("port: %s", parseIni.getValue(i->c_str(), "port"));
		KY_LOG_INFO("dbname: %s", parseIni.getValue(i->c_str(), "dbname"));
		KY_LOG_INFO("user: %s", parseIni.getValue(i->c_str(), "user"));
		KY_LOG_INFO("pass: %s", parseIni.getValue(i->c_str(), "pass"));
	}

	return 0;
}
