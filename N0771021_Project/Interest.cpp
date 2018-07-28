#include "Interest.h"


Interest::Interest(std::string pName, Date pDate, double pAmount, Type pType)
	:Transaction(pName,pDate, pAmount)
{
	type = pType;
}

Interest::~Interest()
{
}

const std::string Interest::display()
{
	std::string result = "INT" ;
	result += " ";

	result += getDate() + " ";
	result += getAmountString() + " ";

	result += getType();
	return result;
}

const std::string Interest::displayWithDelimiter(const char delimiter)
{
	std::string result = "INT";
	result += delimiter;

	//result += getName() + delimiter;
	result += getDateWithDelimiter(delimiter);
	result += delimiter;
	result += getAmountString();
	result += delimiter;

	result += getType();
	return result;
}

const std::string Interest::getType()
{
	switch (type)
	{
	case DAILY: return "Daily";
	case MONTHLY: return "Monthly";
	case ANNUAL: return "Annual";
	default: return "ERROR";
	}
}

const Interest::Type Interest::getInterestType(int id)
{
	Interest::Type type;
	switch (id)
	{
	case 1:
		type = Interest::DAILY;
		break;
	case 2:
		type = Interest::MONTHLY;
		break;
	case 3:
		type = Interest::ANNUAL;
		break;
	default:
		break;
	}
	return type;
}

const int Interest::getInterestTypeFromString(std::string name)
{
	static const std::map<std::string, int> types
	{
		{ "DAILY", 1 },
		{ "MONTHLY", 2 },
		{ "ANNUAL", 3 }
	};

	for (auto & c : name) c = toupper(c); //convert all characters to upper case
	auto search = types.find((name));
	if (search != types.end())
		return search->second;
	else //must make sure user gives correct input. 
		return -1;
}
