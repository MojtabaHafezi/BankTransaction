#pragma once
#include <string>
#include <iomanip>
#include <ctime>
#include <map>
class Date
{

private:
	int day;
	int month;
	int year;
	int hour;
	int min;
	int sec;

public:
	Date(int, int, int, int, int, int);
	Date();
	Date& operator=(Date other);
	const std::string displayTime();
	const std::string displayTimeWithDelimiter(const char pDelimiter);
	const time_t getTime();
	const int getDay();
	const int getMonth();
	const int getYear();
	const int getHour();
	const int getMin();
	const int getSec();
	static const int getMonthByName(std::string name);
	~Date();
};

