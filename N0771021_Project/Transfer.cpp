/*
Plagiarism Declaration
I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct and dealt with accordingly.
I understand that if I lend this piece of work to another student and they copy all or part of it, either with or
without my knowledge or permission, I shall be guilty of collusion.  In submitting this work, I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.

Name: Mojtaba Hafezi ID No: N0771021
*/

#include "Transfer.h"

Transfer::Transfer(std::string pName, Date pDate, double pAmount, std::string pAccNumber, std::string pBankSort)
	:Transaction(pName, pDate, pAmount)
{
	accountNumber = pAccNumber;
	bankSortCode = pBankSort;
}

Transfer::~Transfer()
{}

const std::string Transfer::display()
{
	std::string result = "TR";
	result += " ";


	result += getDate() + " ";
	result += getAmountString() + " ";

	result += getAccountNumber() + " ";
	result += getBankSortCode();

	return result;
}

const std::string Transfer::displayWithDelimiter(const char delimiter)
{
	std::string result = "TR";
	result += delimiter;

	result += getDateWithDelimiter(delimiter);
	result += delimiter;
	result += getAmountString();
	result += delimiter;

	result += getAccountNumber();
	result += delimiter;
	result += getBankSortCode();

	return result;
}

const std::string Transfer::getAccountNumber()
{
	return accountNumber;
}

const std::string Transfer::getBankSortCode()
{
	return bankSortCode;
}


