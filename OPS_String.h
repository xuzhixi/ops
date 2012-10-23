//===============================================
/**
 *  @file OPS_String.h
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 14:34:06
 *  Last   modified:  2012-10-23 14:48:18
 *
 *  Description: 
 */
//================================================

#ifndef __OPS_STRING_H
#define __OPS_STRING_H

#include <string>

using std::string;

namespace OPS
{

class String
{
	public:
		static int	  toInt(string str);
		static long	  toLong(string str);
		static double toDouble(string str);
		static bool	  toBool(string str);
		static string toString(int i);
		static string toString(long l);
		static string toString(double d);
		static string toString(bool b);
};

}

#endif // __OPS_STRING_H
