#include "Transaction.h"

/*
For time conversion:
https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
*/

Transaction::Transaction(std::string pName, Date pDate, double pAmount)
{
	name = pName;
	date = pDate;
	amount = pAmount;
}

Transaction::~Transaction()
{
}


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

const std::string Transaction::getAmountString()
{
	std::string result;
	// Get string with precision 2 after decimal point - stream needed as string has 6 by default
	std::ostringstream streamObj;
	streamObj << std::fixed;
	streamObj << std::setprecision(2);
	streamObj << getAmount();
	result = streamObj.str();
	return result;
}


