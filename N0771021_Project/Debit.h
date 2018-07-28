#pragma once
#include "Transaction.h"
#include <sstream>
#include <string>

#include <ctype.h>

class Debit :
	public Transaction
{
public:
	enum Authorisation { ONLINE, PHONE, MAILORDER };
	Debit(std::string pName, Date pDate, double pAmount, std::string pCard, std::string pRetailerName, std::string pLocation, Authorisation pAuth);
	~Debit();
	const std::string display();
	const std::string displayWithDelimiter(const char delimiter);
	const std::string getCardNumber();
	const std::string getRetailerName();
	const std::string getRetailerLocation();
	const std::string getAuthorisation();
	static const Authorisation getAuthorisationType(int id);

	static const int getAuthorisationTypeFromString(std::string name);
	
	

private:
	Authorisation authorisation;
	std::string cardNumber;
	std::string retailerName;
	std::string retailerLocation;
};

