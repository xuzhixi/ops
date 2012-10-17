//===============================================
/**
 *  @file OPS_ParseOpt.cpp
 *
 *  @author XuZhiXi
 *  Email   932834199@qq.com or 932834199@163.com
 *
 *  Create datetime:  2012-10-17 08:19:17
 *  Last   modified:  2012-10-17 08:19:17
 *
 *  Description: 
 */
//================================================

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "OPS_ParseOpt.h"

using OPS::ParseOpt;

bool ParseOpt::parse(int argc, char *const argv[], const char *optstring)
{
	char c;
	const char *s = optstring;

	while ( *s != '\0' )
	{
		if ( *s != ':' )
		{
			if ( strcmp(s+1, "::") == 0 )
			{
				this->optTypeMap[ *s ] = 2;
				s += 3;
			}
			else if ( s[1] == ':' )
			{
				this->optTypeMap[ *s ] = 2;
				s += 2;
			}
			else
			{
				this->optTypeMap[ *s ] = 1;
				s++;
			}
		}
		else
		{
			s++;
		}
	}

	while ((c = getopt(argc, argv, optstring)) != -1)
	{
		if ( this->optTypeMap.find(c) != this->optTypeMap.end() )
		{
			if ( this->optTypeMap[c] == 1 )
			{
				this->optMap[c] = "1";
				if ( this->optContentMap.find(c) != this->optContentMap.end() )
				{
					printf("%s", this->optContentMap[c].c_str());
					return false;
				}
			}
			else if ( this->optTypeMap[c] == 2 )
			{
				if ( optarg == NULL || optarg[0] == '-' )
				{
					printf("option: -%c can not is null\n", c);
					return false;
				}
				else
				{
					this->optMap[c] = optarg;
				}
			}
		}
		else
		{
			printf("Invalid option: -%c\n", (char)optopt);
			return false;
		}
	}

	return true;
}

void ParseOpt::setOptContent(char opt, string content)
{
	this->optContentMap[opt] = content;	
}

bool ParseOpt::isSet(char opt)
{
	if ( this->optTypeMap.find( opt ) != this->optTypeMap.end() )
	{
		return true;
	}
	else
	{
		return false;
	}
}

string ParseOpt::getString(char opt, string defaultValue)
{
	if ( this->optMap.find(opt) != this->optMap.end() )
	{
		return this->optMap[opt];
	}
	else
	{
		return defaultValue;
	}
}

int ParseOpt::getInt(char opt, int defaultValue)
{
	if ( this->optMap.find(opt) != this->optMap.end() )
	{
		return atoi( this->optMap[opt].c_str() );
	}
	else
	{
		return defaultValue;
	}
}

long ParseOpt::getLong(char opt, long defaultValue)
{
	if ( this->optMap.find(opt) != this->optMap.end() )
	{
		return atol( this->optMap[opt].c_str() );
	}
	else
	{
		return defaultValue;
	}
}

