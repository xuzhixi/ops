#include <stdio.h>
#include <string>
#include "ops_parseopt.h"

using OPS::ParseOpt;
using std::string;

int main(int argc, char *argv[])
{
	ParseOpt opt;
	int b;
	long c;
	string e;

	opt.setOptContent('h', "Usage: ./a.out -a -b -c -d -e -h\n");
	if ( opt.parse(argc, argv, "ab:c:de::h") == true )
	{
		b = opt.getInt('b', 5);
		c = opt.getLong('c', 222222);
		e = opt.getString('e', "default");

		printf("b:%d c:%ld, e:%s\n", b, c, e.c_str());
	}
	else
	{
		printf("fail!\n");
	}

	return 0;
}
