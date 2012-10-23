//===============================================
/**
 *  @file OPS_ParseIni.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 10:28:06
 *  Last   modified:  2012-10-23 12:10:05
 *
 *  Description: 
 */
//================================================

#include "ky_log.h"
#include "OPS_ParseIni.h"

namespace OPS
{

	ParseIni::ParseIni(const char *fileName)
	{
		this->ini.SetUnicode();
		SI_Error rs = this->ini.LoadFile( fileName );
		if ( rs < 0 )
		{
			KY_LOG_ERROR("load ini file(%s) fail!", fileName);
			return;
		}
	}

	list<string> ParseIni::getAllSections()
	{
		CSimpleIniA::TNamesDepend sections;
		CSimpleIniA::TNamesDepend::iterator i;
		list<string> sectionList;

		ini.GetAllSections(sections);
		for (i=sections.begin(); i!=sections.end(); ++i)
		{
			sectionList.push_back( i->pItem );
		}

		return sectionList;
	}

	const char *ParseIni::getValue(const char *section, const char *key, const char *defaultVal)
	{
		return this->ini.GetValue(section, key, defaultVal);
	}

	bool ParseIni::setValue(const char *section, const char *key, const char *value, const char *comment)
	{
		SI_Error rs = this->ini.SetValue(section, key, value, comment);
		if ( rs < 0 )
		{
			KY_LOG_WARN("ini file set value error, section:%s key: %s value: %s comment: %s", section, key, value, comment);
			return false;
		}

		return true;
	}

	bool ParseIni::remove(const char *section, const char *key, bool delEmpty)
	{
		return this->ini.Delete(section, key, delEmpty);
	}

	bool ParseIni::save(const char *fileName)
	{
		SI_Error rs = this->ini.SaveFile(fileName);
		if ( rs < 0 )
		{
			KY_LOG_ERROR("save ini file(%s) error!", fileName);
			return false;
		}

		return true;
	}
}
