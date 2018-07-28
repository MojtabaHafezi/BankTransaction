/*
Plagiarism Declaration
I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct and dealt with accordingly.
I understand that if I lend this piece of work to another student and they copy all or part of it, either with or
without my knowledge or permission, I shall be guilty of collusion.  In submitting this work, I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.

Name: Mojtaba Hafezi ID No: N0771021
*/

#pragma once
#include <string>
#include <iomanip>
#include <ctime>
#include <map>

//A class used to store the date. Also provides the functionality to return the date in seconds using the ctime library.
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
	//Constructor takes the variables as integer values.
	Date(int, int, int, int, int, int);
	Date();
	/*---------------------------------------------*/
	/* Purpose: Assignment operator for copying the data of another Date object.
	/* Input parameters: other Date object from which the data should be copied.
	/* Output parameters: reference to the current Date object.
	/* Precondition: No empty Date object
	/* Postcondition: The called Date object has the same attributes as the given Date object.
	/*---------------------------------------------*/
	Date& operator=(Date other);
	/*---------------------------------------------*/
	/* Purpose: Returns a string containing the date in the given format by the test data.
	/* Output parameters: String containing the correct date.
	/* Global variable in use: static const array of strings called monthName - no changes
	/*---------------------------------------------*/
	const std::string displayTime();
	const std::string displayTimeWithDelimiter(const char pDelimiter);
	/*---------------------------------------------*/
	/* Purpose: Returns the time since 1 January 1900 till this Date objects set date. Used for easier comparison.
	/* Output parameters: Time in time_t format. Can be used to return the date in seconds.
	/*---------------------------------------------*/
	const time_t getTime();
	const int getDay();
	const int getMonth();
	const int getYear();
	const int getHour();
	const int getMin();
	const int getSec();
	/*---------------------------------------------*/
	/* Purpose: Uses a map to find the month in integer by given month name.
	/* Input parameters: Name of the month in abbreviated form (January = Jan etc.)
	/* Output parameters: Month as integer.
	/* Precondition: Given string is a valid month abb.
	/* Global variable in use: static const map called months - no changes
	/*---------------------------------------------*/
	static const int getMonthByName(std::string name);
	~Date();
};

