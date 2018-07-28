/*
Plagiarism Declaration
I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct and dealt with accordingly.
I understand that if I lend this piece of work to another student and they copy all or part of it, either with or
without my knowledge or permission, I shall be guilty of collusion.  In submitting this work, I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.

Name: Mojtaba Hafezi ID No: N0771021
*/

#include "Transaction.h"

Transaction::Transaction(std::string pName, Date pDate, double pAmount)
{
	name = pName;
	date = pDate;
	amount = pAmount;
}

Transaction::~Transaction()
{}

const std::string Transaction::getName()
{
	return name;
}

const std::string Transaction::getDate()
{
	return date.displayTime();
}

const std::string Transaction::getDateWithDelimiter(const char delimiter)
{
	return date.displayTime();
}

time_t Transaction::getTime()
{
	return date.getTime();
}

const double Transaction::getAmount()
{
	return amount;
}

/***************************************************************************************
*	 General idea of this implementation from:
*    Title: C++ : Convert double to string and manage precision | scientific notation
*    Author: Varun
*    Date: June 29, 2017
*    Code version: N.A.
*    Availability: http://thispointer.com/c-convert-double-to-string-and-manage-precision-scientific-notation/
*
***************************************************************************************/
const std::string Transaction::getAmountString()
{
	std::string result;
	std::ostringstream streamObj;
	streamObj << std::fixed;
	streamObj << std::setprecision(2);
	streamObj << getAmount();
	result = streamObj.str();
	return result;
}


