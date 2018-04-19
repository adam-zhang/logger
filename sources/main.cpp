#include "Logger.h"

int main(int,char**)
{
	Logger::instance().debug("Hello");
	Logger::instance().debug(L"Hello");
	Logger::instance().debug("Hello", 100);
	Logger::instance().debug(L"Hello", 200);
	Logger::instance().debug("char", "char");
	Logger::instance().debug("char", L"wchar");
	Logger::instance().debug(L"wchar", L"wchar");
	Logger::instance().debug(L"wchar", "char");
	return 0;
}
