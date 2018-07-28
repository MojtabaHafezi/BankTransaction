#include "DirectDebit.h"

DirectDebit::DirectDebit(std::string pName, Date pDate, double pAmount, std::string pReferenceNumber)
	:Transaction(pName, pDate, pAmount)
{
	referenceNumber = pReferenceNumber;
}

DirectDebit::~DirectDebit()
{
}

const std::string DirectDebit::getReferenceNumber()
{
	return referenceNumber;
}

const std::string DirectDebit::displayWithDelimiter(const char delimiter)
{
	std::string result = "DD";
	result += delimiter;

	result += getDateWithDelimiter(delimiter);
	result += delimiter;
	result += getAmountString();
	result += delimiter;

	result += getReferenceNumber();
	return result;
}

const std::string DirectDebit::display()
{

	std::string result = "DD";
	result += " ";

	result += getDate() + " ";
	result += getAmountString() + " ";

	result += getReferenceNumber();
	return result;
}
