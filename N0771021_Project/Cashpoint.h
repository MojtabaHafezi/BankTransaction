#pragma once
#include "Transaction.h"
class Cashpoint :
	public Transaction
{
public:
	Cashpoint(std::string pName, Date pDate, double pAmount, std::string plocationId, std::string pCardNumber);
	~Cashpoint();
	const std::string display();
	const std::string displayWithDelimiter(const char delimiter);
	const std::string getLocationId();
	const std::string getCardNumber();

private:
	std::string locationId;
	std::string cardNumber;
};

