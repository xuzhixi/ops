//===============================================
/**
 *  @file OPS_ParseIni.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 10:28:49
 *  Last   modified:  2012-10-23 12:09:47
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_PARSEINI_H
#define __OPS_PARSEINI_H

#include <list>
#include <string>
#include "simpleini/SimpleIni.h"

using std::list;
using std::string;

namespace OPS
{

	class ParseIni
	{
		public:
			ParseIni(const char *fileName);
			/**
			 * @brief 获取所有section名称的一个列表
			 */
			list<string> getAllSections();
			/**
			 * @brief 获取指定section, 指定key对应的值，没有找到则返回defaultVal
			 */
			const char *getValue(const char *section, const char *key, const char *defaultVal=NULL);
			/**
			 * @brief 添加或更新一个section或者key 
			 *
			 * @param  section		添加或更新section
			 * @param  key			添加或更新键。设置为NULL, 创建一个空的section
			 * @param  value		设置值。设置为NULL, 创建一个空的section
			 * @param  comment		注释
			 */
			bool setValue(const char *section, const char *key, const char *value, const char *comment=NULL);
			/**
			 * @param  section	 删除section中的键，如果Key是NULL，section整个删除
			 * @param  key		 从指定的section中删除一个key。设置为NULL删除整个section
			 * @param  delEmpty  删除一个section中的key之后，如果section是空的了，此section是否可以删除
			 * @retval true		 key或section被删除
			 * @retval false	 key或section没有找到
			 */
			bool remove(const char *section, const char *key=NULL, bool delEmpty=false);
			/**
			 * @brief 保存到文件
			 */
			bool save(const char *fileName);

		private:
			CSimpleIniA ini;
	};

}

#endif // __OPS_PARSEINI_H
