#pragma once
#include "Transaction.h"
class Creditpoint :
	public Transaction
{
public:
	enum Type {CHEQUE, CASH};
	Creditpoint(std::string pName, Date pDate, double pAmount, Type pType);
	~Creditpoint();
	const std::string display();
	const std::string displayWithDelimiter(const char delimiter);
	static const Type getCreditpointType(int id);
	static const int getCreditpointTypeFromString(std::string name);
	const std::string getType();

private: 
	Type type;

};

