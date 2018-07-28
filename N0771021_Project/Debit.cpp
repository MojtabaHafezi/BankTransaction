#include "Debit.h"


Debit::Debit(std::string pName, Date pDate, double pAmount, std::string pCard, std::string pRetailerName, std::string pLocation, Authorisation pAuth)
	:Transaction(pName, pDate, pAmount)
{
	cardNumber = pCard;
	retailerName = pRetailerName;
	retailerLocation = pLocation;
	authorisation = pAuth;
}

Debit::~Debit()
{
}

const std::string Debit::display()
{
	std::string result = "DB";
	result += " ";

	result += getDate() + " ";
	result += getAmountString() + " ";


	result += getCardNumber() + " ";
	result += getRetailerName() + " ";
	result += getRetailerLocation() + " ";
	result += getAuthorisation() + " ";

	return result;
}

const std::string Debit::displayWithDelimiter(const char delimiter)
{
	std::string result = "DB";
	result += delimiter;

	result += getDateWithDelimiter(delimiter);
	result += delimiter;
	result += getAmountString();
	result += delimiter;


	result += getCardNumber();
	result += delimiter;
	result += getRetailerName();
	result += delimiter;
	result += getRetailerLocation();
	result += delimiter;
	result += getAuthorisation();
	result += delimiter;
	return result;
}

const std::string Debit::getCardNumber()
{
	return cardNumber;
}

const std::string Debit::getRetailerName()
{
	return retailerName;
}

const std::string Debit::getRetailerLocation()
{
	return retailerLocation;
}

const std::string Debit::getAuthorisation()
{
	switch (authorisation)
	{
	case MAILORDER: return "mailorder";
	case ONLINE: return "online";
	case PHONE: return "phone";
	default: return "ERROR";
	}
}


const Debit::Authorisation Debit::getAuthorisationType(int id)
{
	Debit::Authorisation auth;
	switch (id)
	{
	case 1:
		auth = Debit::Authorisation::ONLINE;
		break;
	case 2:
		auth = Debit::Authorisation::PHONE;
		break;
	case 3:
		auth = Debit::Authorisation::MAILORDER;
		break;
	default: /// TODO: throw error
		break;
	}
	return auth;
}

const int Debit::getAuthorisationTypeFromString(std::string name)
{
	static const std::map<std::string, int> types
	{
		{ "ONLINE", 1 },
		{ "PHONE", 2 },
		{ "MAILORDER", 3 }
	};
	
	for (auto & c : name) c = toupper(c); //convert all characters to upper case
	auto search = types.find((name));
	if (search != types.end())
		return search->second;
	else //must make sure user gives correct input. 
		return -1;
}