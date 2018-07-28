/*
Plagiarism Declaration
I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct and dealt with accordingly.
I understand that if I lend this piece of work to another student and they copy all or part of it, either with or
without my knowledge or permission, I shall be guilty of collusion.  In submitting this work, I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.

Name: Mojtaba Hafezi ID No: N0771021
*/

#include "Cashpoint.h"

Cashpoint::Cashpoint(std::string pName, Date pDate, double pAmount, std::string plocationId, std::string pCardNumber)
	:Transaction(pName, pDate, pAmount)
{
	locationId = plocationId;
	cardNumber = pCardNumber;
}

Cashpoint::~Cashpoint()
{}

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
