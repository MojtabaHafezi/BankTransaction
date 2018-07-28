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
#include <map>
#include<iostream>
#include<sstream>
#include <iomanip>
#include <ctime>
#include "Date.h"

//Base class for all transaction objects.
class Transaction
{
private:
	std::string name; //Kind of transaction
	Date date; //The specific date 
	double amount; //Amount in pounds & pence

public:
	Transaction(std::string pName, Date pDate, double pAmount);
	virtual ~Transaction();
	/*---------------------------------------------*/
	/* Purpose:Specification requires the transaction class to be abstract.
	/* Without this specification I would have changed this method to be virtual 
	/* only so that the code is not repeated in the derived classes for getting
	/* the basic attributes like name, date and amount.                                                      
	/*---------------------------------------------*/
	virtual const std::string display() = 0; // To be done in the derived classes
	virtual const std::string displayWithDelimiter(const char delimiter) = 0;

	const std::string getName();
	const std::string getDate();
	const std::string getDateWithDelimiter(const char delimiter);
	/*---------------------------------------------*/
	/* Purpose: Returns the time in a type of time_t - the date can't be changed after initialization.
	/*---------------------------------------------*/
	time_t getTime();
	const double getAmount();
	/*---------------------------------------------*/
	/* Purpose:Specification requires the transaction class to be abstract.
	/* Get string with precision 2 after decimal point - uses 	std::ostringstream as the standard string has
	/* a precision of 6 by default
	/* Output parameters: a string representing the amount of the transaction with the precision of 2 after decimal for pence
	/*---------------------------------------------*/
	const std::string getAmountString();

};

