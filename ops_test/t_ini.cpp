#include "ky_log.h"
#include "simpleini/SimpleIni.h"

int main()
{
	CSimpleIniA ini;  
	ini.SetUnicode();  
	ini.LoadFile("room.ini");  
	const char *pVal = ini.GetValue("DataBase_1", "host2", "localhost");  
	KY_LOG_INFO("pVal: %s", pVal);
	if ( pVal == "localhost" )
	{
		KY_LOG_WARN("save parameter point!!!");
	}
	ini.SetValue("section", "key", "newvalue");  
	ini.SaveFile("room.ini.bak");

	CSimpleIniA::TNamesDepend sections;
	ini.GetAllSections(sections);
	CSimpleIniA::TNamesDepend::iterator i;
	for (i = sections.begin(); i != sections.end(); ++i) 
	{ 
		    KY_LOG_INFO("key-name = '%s'", i->pItem);
	}

	return 0;
}
