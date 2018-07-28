/*
Plagiarism Declaration
I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct and dealt with accordingly.
I understand that if I lend this piece of work to another student and they copy all or part of it, either with or
without my knowledge or permission, I shall be guilty of collusion.  In submitting this work, I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.

Name: Mojtaba Hafezi ID No: N0771021
*/

#include "DirectDebit.h"

DirectDebit::DirectDebit(std::string pName, Date pDate, double pAmount, std::string pReferenceNumber)
	:Transaction(pName, pDate, pAmount)
{
	referenceNumber = pReferenceNumber;
}

DirectDebit::~DirectDebit()
{}

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
