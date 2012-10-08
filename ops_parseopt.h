#ifndef __OPS_PARSEOPT_H
#define __OPS_PARSEOPT_H

#include <string>
#include <map>

using std::string;
using std::map;

namespace OPS
{

class ParseOpt
{
	public:
		bool parse(int argc, char *const argv[], const char *optstring);
		void setOptContent(char opt, string content);
		bool isSet(char opt);
		string getString(char opt, string defaultValue);
		int getInt(char opt, int defaultValue);
		long getLong(char opt, long defaultValue);

	private:
		map<char, string> optContentMap;
		map<char, int> optTypeMap;
		map<char, string> optMap;
};

}

#endif // __OPS_PARSEOPT_H
