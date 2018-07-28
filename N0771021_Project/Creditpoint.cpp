#include "Creditpoint.h"





Creditpoint::Creditpoint(std::string pName, Date pDate, double pAmount, Type pType)
	:Transaction(pName, pDate, pAmount)
{
	type = pType;
}

Creditpoint::~Creditpoint()
{
}

const std::string Creditpoint::display()
{
	std::string result = "CDP";
	result += " ";

	result += getDate() + " ";
	result += getAmountString() + " ";

	result += getType() + " ";
	return result;
}

const std::string Creditpoint::displayWithDelimiter(const char delimiter)
{
	std::string result = "CDP";
	result += delimiter;

	//result += getName() + delimiter;
	result += getDateWithDelimiter(delimiter) + delimiter;
	result += getAmountString() + delimiter;

	result += getType() + delimiter;
	return result;
}

const Creditpoint::Type Creditpoint::getCreditpointType(int id)
{
	Creditpoint::Type type;
	switch (id)
	{
	case 1:
		type = Creditpoint::CHEQUE;
		break;
	case 2:
		type = Creditpoint::CASH;
		break;
	default:
		break;
	}

	return type;
}

const int Creditpoint::getCreditpointTypeFromString(std::string name)
{
	static const std::map<std::string, int> types
	{
		{ "CHEQUE", 1 },
		{ "CASH", 2 }
	};

	for (auto & c : name) c = toupper(c); //convert all characters to upper case
	auto search = types.find((name));
	if (search != types.end())
		return search->second;
	else //must make sure user gives correct input. 
		return -1;
}

const std::string Creditpoint::getType()
{
	switch (type)
	{
	case CHEQUE:
		return "Cheque";
		break;
	case CASH:
		return "Cash";
		break;
	default:
		return "ERROR";
	}

}
