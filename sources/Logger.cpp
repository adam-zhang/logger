#include "Logger.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cassert>

using namespace std;

Logger::Logger()
{
}

Logger::~Logger()
{
}

//template<typename charT>
//class GetTime
//{
//	public:
//		basic_string<charT> operator() 
//		{
//			return basic_string<charT>();
//		}
//}

template<typename charT>
basic_string<charT> getTime()
{
	return basic_string<charT>();
}

template<>
basic_string<char>getTime()
{
	auto tm = time(NULL);
	string s = asctime(localtime(&tm));
	return s.substr(0, s.size() - 1);
}

template<>
basic_string<wchar_t> getTime()
{
	string s = getTime<char>();
	basic_string<wchar_t> ws;
	copy(s.begin(), s.end(), back_inserter(ws));
	return ws;
}

template<typename charT>
basic_string<charT> addTimeInfo(const basic_string<charT>& message)
{
	basic_stringstream<charT> ss;
	ss << getTime<charT>() << ":" << message ;
	return ss.str();
}


template<typename charT>
void writeToConsole(const basic_string<charT>& message)
{
}

template<>
void writeToConsole<char>(const basic_string<char>& message)
{
	cerr << addTimeInfo<char>(message) << endl;
}

template<>
void writeToConsole<wchar_t>(const basic_string<wchar_t>& message)
{
	wcerr << addTimeInfo<wchar_t>(message) << endl;
}

void Logger::debug(const std::string& message)
{
	//cout << getTime<char>() << std::endl;
	writeToConsole(message);
	//cin.get();
}

void Logger::debug(const std::wstring& message)
{
	writeToConsole(message);
}

void Logger::debug(const std::string& notification, size_t value)
{
	stringstream ss;
	ss << notification << ":" << value;
	debug(ss.str());
}

void Logger::debug(const std::wstring& notification, size_t value)
{
	wstringstream ss;
	ss << notification << L":" << value;
	debug(ss.str());
}

void Logger::debug(const std::string& notification, const std::string& value)
{
	stringstream ss;
	ss << notification << ":" << value;
	debug(ss.str());
}

static wstring convert(const std::string& value)
{
	vector<wchar_t> buffer(value.size() + 1);
	size_t s = mbstowcs(&buffer[0], value.c_str(), value.size());
	assert(s == value.size());
	return &buffer[0];
}

void Logger::debug(const string& notification, const wstring& value)
{
	wstringstream ss;
	ss << convert(notification) << ":" << value;
	debug(ss.str());
}

void Logger::debug(const wstring& notification, const wstring& value)
{
	wstringstream ss;
	ss << notification << L":" << value;
	debug(ss.str());
}

void Logger::debug(const wstring& notification, const string& value)
{
	wstringstream ss;
	ss << notification << L":" << convert(value);
}
