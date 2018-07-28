#include "Cashpoint.h"

Cashpoint::Cashpoint(std::string pName, Date pDate, double pAmount, std::string plocationId, std::string pCardNumber)
	:Transaction(pName, pDate, pAmount)
{
	locationId = plocationId;
	cardNumber = pCardNumber;
}

Cashpoint::~Cashpoint()
{
}

const std::string Cashpoint::display()
{
	std::string result = "CSP";
	result += " ";

	result += getDate() + " ";
	result += getAmountString() + " ";

	result += getLocationId() + " ";
	result += getCardNumber() + " ";

	return result;
}

const std::string Cashpoint::displayWithDelimiter(const char delimiter)
{
	std::string result = "CSP";
	result += delimiter;

	//result += getName() + delimiter;
	result += getDateWithDelimiter(delimiter);
	result += delimiter;
	result += getAmountString();
	result += delimiter;


	result += getLocationId();
	result += delimiter;
	result += getCardNumber();
	result += delimiter;


	return result;
}


const std::string Cashpoint::getLocationId()
{
	return locationId;
}

const std::string Cashpoint::getCardNumber()
{
	return cardNumber;
}
