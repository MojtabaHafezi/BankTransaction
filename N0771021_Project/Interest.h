#pragma once
#include "Transaction.h"

class Interest :
	public Transaction
{
public:
	enum Type{DAILY, MONTHLY, ANNUAL};
	Interest(std::string pName, Date pDate, double pAmount, Type pType);
	~Interest();
	const std::string display();
	const std::string displayWithDelimiter(const char delimiter);
	const std::string getType();
	static const Type getInterestType(int id);
	static const int getInterestTypeFromString(std::string name);
private:
	Type type;
};

