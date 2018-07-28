#include "Date.h"

Date::Date(int pYear, int pMonth, int pDay, int pHour, int pMin, int pSec)
{
	day = pDay;
	month = pMonth;
	year = pYear;
	hour = pHour;
	min = pMin;
	sec = pSec;
}

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
	hour = 0;
	min = 0;
	sec = 0;
}

Date & Date::operator=(Date other)
{
	year = other.year;
	month = other.month;
	day = other.day;
	hour = other.hour;
	min = other.min;
	sec = other.sec;
	return *this;
}

const std::string Date::displayTime()
{
	std::string result = "";
	std::string monthName[] = { "Jan", "Feb", "Mar",
		"Apr", "May", "Jun", "Jul",
		"Aug", "Sep", "Oct",
		"Nov", "Dec" };
	if (getDay() <= 9)
		result += "0";
	result += std::to_string(getDay());
	result += " ";
	result += monthName[getMonth() - 1];
	result += " ";
	result += std::to_string(getYear());
	result += " ";
	if (getHour() <= 9)
		result += "0";
	result += std::to_string(getHour());
	result += ":";
	if (getMin() <= 9)
		result += "0";
	result += std::to_string(getMin());
	result += ":";
	if (getSec() <= 9)
		result += "0";
	result += std::to_string(getSec());
	return result;
}

const std::string Date::displayTimeWithDelimiter(const char pDelimiter)
{
	std::string result = "";
	std::string monthName[] = { "Jan", "Feb", "Mar",
		"Apr", "May", "Jun", "Jul",
		"Aug", "Sep", "Oct",
		"Nov", "Dec" };
	if (getDay() <= 9)
		result += "0";
	result += std::to_string(getDay());
	result += pDelimiter;
	result += monthName[getMonth() - 1];
	result += pDelimiter;
	result += std::to_string(getYear());
	result += pDelimiter;
	if (getHour() <= 9)
		result += "0";
	result += std::to_string(getHour());
	result += ":";
	if (getMin() <= 9)
		result += "0";
	result += std::to_string(getMin());
	result += ":";
	if (getSec() <= 9)
		result += "0";
	result += std::to_string(getSec());
	return result;
}

const time_t Date::getTime()
{
	//since time starts at 1900, January.
	struct tm date = { 0 }; //initialisation to 0 suggested
	date.tm_year = getYear() - 1900;  //years since 1900
	date.tm_mon = getMonth() - 1; // 0-11
	date.tm_mday = getDay();
	date.tm_hour = getHour();
	date.tm_min = getMin();
	date.tm_sec = getSec();

	time_t timeInSec = std::mktime(&date);
	return timeInSec;
}

const int Date::getDay()
{
	return day;
}

const int Date::getMonth()
{
	return month;
}

const int Date::getYear()
{
	return year;
}

const int Date::getHour()
{
	return hour;
}

const int Date::getMin()
{
	return min;
}

const int Date::getSec()
{
	return sec;
}

//could do the same to get monthname by passing getMonth() 
const int Date::getMonthByName(std::string name)
{
	static const std::map<std::string, int> months
	{
		{ "Jan", 1 },
		{ "Feb", 2 },
		{ "Mar", 3 },
		{ "Apr", 4 },
		{ "May", 5 },
		{ "Jun", 6 },
		{ "Jul", 7 },
		{ "Aug", 8 },
		{ "Sep", 9 },
		{ "Oct", 10 },
		{ "Nov", 11 },
		{ "Dec", 12 }
	};
	auto search = months.find(name);
	if (search != months.end())
		return search->second;
	else //must make sure user gives correct months. 
		return -1;
}

Date::~Date()
{
}
