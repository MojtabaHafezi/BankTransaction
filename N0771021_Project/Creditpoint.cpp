/*
Plagiarism Declaration
I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct and dealt with accordingly.
I understand that if I lend this piece of work to another student and they copy all or part of it, either with or
without my knowledge or permission, I shall be guilty of collusion.  In submitting this work, I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.

Name: Mojtaba Hafezi ID No: N0771021
*/

#include "Creditpoint.h"


//maps a string to an integer and can be used to find the corresponding data.
static const std::map<std::string, int> types
{
	{ "CHEQUE", 1 },
	{ "CASH", 2 }
};

Creditpoint::Creditpoint(std::string pName, Date pDate, double pAmount, Type pType)
	:Transaction(pName, pDate, pAmount)
{
	type = pType;
}

Creditpoint::~Creditpoint()
{}

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
/***************************************************************************************
*	 General idea of this implementation from:
*    Title: how can I map an int to a corresponding string in C/C++
*    Author: R Samuel Klatchko
*    Date: 2017
*    Code version: N.A.
*    Availability:https://stackoverflow.com/questions/1910733/how-can-i-map-an-int-to-a-corresponding-string-in-c-c
*
***************************************************************************************/
const int Creditpoint::getCreditpointTypeFromString(std::string name)
{
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
