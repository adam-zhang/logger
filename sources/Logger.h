#ifndef __LOGGER__H
#define __LOGGER__H

#include <string>
#include "Singleton.h"

class Logger : public Singleton<Logger>
{
    public:
        Logger();
        ~Logger();

    public:
	void debug(const std::string& message);
	void debug(const std::wstring& message);
	void debug(const std::string& notification, size_t value);
	void debug(const std::wstring& notification, size_t value);
	void debug(const std::string&, const std::string&);
	void debug(const std::string&, const std::wstring&);
	void debug(const std::wstring&, const std::wstring&);
	void debug(const std::wstring&, const std::string&);
};
#endif//__LOGGER__H
