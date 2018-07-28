#pragma once
#include "Transaction.h"

class DirectDebit :
	public Transaction
{
public:
	DirectDebit(std::string pName, Date pDate, double pAmount, std::string pReferenceNumber);
	~DirectDebit();
	const std::string getReferenceNumber();
	const std::string display();
	const std::string displayWithDelimiter(const char delimiter);
private:
	std::string referenceNumber;
};

