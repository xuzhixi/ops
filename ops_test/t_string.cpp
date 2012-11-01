#include "ky_log.h"
#include "OPS_String.h"

using OPS::String;

int main()
{
	KY_LOG_INFO("int: %s", String::toString(100).c_str());	
	KY_LOG_INFO("long: %s", String::toString(8).c_str());
	KY_LOG_INFO("float: %s", String::toString(7.85).c_str());
	KY_LOG_INFO("bool: %s", String::toString(true).c_str());

	KY_LOG_INFO("toInt: %d", String::toInt("z5s"));

	return 0;
}
