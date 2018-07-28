#include "Transfer.h"



Transfer::Transfer(std::string pName, Date pDate, double pAmount, std::string pAccNumber, std::string pBankSort)
	:Transaction(pName, pDate, pAmount)
{
	accountNumber = pAccNumber;
	bankSortCode = pBankSort;
}

Transfer::~Transfer()
{
}

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


