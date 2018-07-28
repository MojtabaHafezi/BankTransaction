/*
Plagiarism Declaration
I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct and dealt with accordingly.
I understand that if I lend this piece of work to another student and they copy all or part of it, either with or
without my knowledge or permission, I shall be guilty of collusion.  In submitting this work, I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.

Name: Mojtaba Hafezi ID No: N0771021
*/

#include "Debit.h"

//maps a string to an integer and can be used to find the corresponding data.
static const std::map<std::string, int> types
{
	{ "ONLINE", 1 },
	{ "PHONE", 2 },
	{ "MAILORDER", 3 }
};

Debit::Debit(std::string pName, Date pDate, double pAmount, std::string pCard, std::string pRetailerName, std::string pLocation, Authorisation pAuth)
	:Transaction(pName, pDate, pAmount)
{
	cardNumber = pCard;
	retailerName = pRetailerName;
	retailerLocation = pLocation;
	authorisation = pAuth;
}

Debit::~Debit()
{}

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

/***************************************************************************************
*	 General idea of this implementation from:
*    Title: how can I map an int to a corresponding string in C/C++
*    Author: R Samuel Klatchko
*    Date: 2017
*    Code version: N.A.
*    Availability:https://stackoverflow.com/questions/1910733/how-can-i-map-an-int-to-a-corresponding-string-in-c-c
*
***************************************************************************************/
const int Debit::getAuthorisationTypeFromString(std::string name)
{
	for (auto & c : name) c = toupper(c); //convert all characters to upper case
	auto search = types.find((name));
	if (search != types.end())
		return search->second;
	else //must make sure user gives correct input. 
		return -1;
}