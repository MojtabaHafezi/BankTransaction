/*
Plagiarism Declaration
I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct and dealt with accordingly.
I understand that if I lend this piece of work to another student and they copy all or part of it, either with or
without my knowledge or permission, I shall be guilty of collusion.  In submitting this work, I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.

Name: Mojtaba Hafezi ID No: N0771021
*/

#include "Date.h"

//Used for returning the abbreviated name of a month for a given integer value. 
static const std::string monthName[] = { "Jan", "Feb", "Mar",
"Apr", "May", "Jun", "Jul",
"Aug", "Sep", "Oct",
"Nov", "Dec" };

//Used for returning the integer value of a month by finding the name in the map.
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

/***************************************************************************************
*	 General idea of this implementation from:
*    Title: C++ Date and Time
*    Author: N.A.
*    Date: 2017
*    Code version: N.A.
*    Availability: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
*
***************************************************************************************/
const time_t Date::getTime()
{
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

/***************************************************************************************
*	 General idea of this implementation from:
*    Title: how can I map an int to a corresponding string in C/C++
*    Author: R Samuel Klatchko
*    Date: 2017
*    Code version: N.A.
*    Availability:https://stackoverflow.com/questions/1910733/how-can-i-map-an-int-to-a-corresponding-string-in-c-c
*
***************************************************************************************/
const int Date::getMonthByName(std::string name)
{
	auto search = months.find(name);
	//if the iterator finds a key (first) -> return the value (second)
	if (search != months.end())
		return search->second;
	else //must make sure user gives correct months. 
		return -1;
}

Date::~Date()
{}
