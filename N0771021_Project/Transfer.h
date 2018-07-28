#pragma once
#include "Transaction.h"
class Transfer :
	public Transaction
{
public:
	Transfer(std::string pName, Date pDate, double pAmount, std::string pAccNumber, std::string pBankSort);
	~Transfer();
	const std::string display();
	const std::string displayWithDelimiter(const char delimiter);
	const std::string getAccountNumber();
	const std::string getBankSortCode();

private:
	std::string accountNumber;
	std::string bankSortCode;
};

