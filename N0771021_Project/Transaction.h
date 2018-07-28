#pragma once
#include <string>
#include <map>
#include<iostream>
#include<sstream>
#include <iomanip>
#include <ctime>
#include "Date.h"

/*
For time conversion:
https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
*/


class Transaction
{
private:
	std::string name;
	Date date;
	double amount; //amount in pounds & pence

public:
	Transaction(std::string pName, Date pDate, double pAmount);
	virtual ~Transaction();
	virtual const std::string display() = 0; // To be done in the derived classes
	virtual const std::string displayWithDelimiter(const char delimiter) = 0;
	const std::string getName();
	const std::string getDate();
	const std::string getDateWithDelimiter(const char delimiter);
	time_t getTime();
	const double getAmount();
	const std::string getAmountString();
	

};

