//===============================================
/**
 *  @file OPS_String.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-23 14:33:20
 *  Last   modified:  2012-10-23 14:52:55
 *
 *  Description: 
 */
//================================================

#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <sstream>
#include "OPS_String.h"

using std::stringstream;

namespace OPS
{

		int String::toInt(string str)
		{
			return atoi( str.c_str() );
		}

		long String::toLong(string str)
		{
			return atol( str.c_str() );
		}

		double String::toDouble(string str)
		{
			return atof( str.c_str() );
		}

		bool String::toBool(string str)
		{
			std::transform(str.begin(), str.end(), str.begin(), ::tolower);
			if ( str == "true" )
			{
				return true;
			}

			return false;
		}

		string String::toString(int i)
		{
			stringstream ss;
			ss << i;
			return ss.str();	
		}

		string String::toString(long l)
		{
			stringstream ss;
			ss << l;
			return ss.str();	
		}

		string String::toString(double d)
		{
			stringstream ss;
			ss << d;
			return ss.str();	
		}

		string String::toString(bool b)
		{
			if ( b == true )
			{
				return "true";
			}

			return "false";
		}
}
