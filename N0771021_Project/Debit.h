/*
Plagiarism Declaration
I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct and dealt with accordingly.
I understand that if I lend this piece of work to another student and they copy all or part of it, either with or
without my knowledge or permission, I shall be guilty of collusion.  In submitting this work, I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.

Name: Mojtaba Hafezi ID No: N0771021
*/

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
	/*---------------------------------------------*/
	/* Purpose: Returns a string with the important details about this transaction object.
	/* The identifier of the object is also added through this method.
	/* Output parameter: A string representing this object with space " " as delimiter.
	/*---------------------------------------------*/
	const std::string display();
	const std::string displayWithDelimiter(const char delimiter);
	const std::string getCardNumber();
	const std::string getRetailerName();
	const std::string getRetailerLocation();
	/*---------------------------------------------*/
	/* Purpose: Uses a switch statement to determine the authorisation and returns a string representing the authorisation type.
	/* Output parameter: Returns a string containing the authorisation type.
	/*---------------------------------------------*/
	const std::string getAuthorisation();
	/*---------------------------------------------*/
	/* Purpose: Determines the type of authorisation and returns it by the given id.
	/* Input parameter: Id of the authorisation type. Should be checked in a real program.
	/* Output parameter: returns which kind of authorisation type this object has.
	/*---------------------------------------------*/
	static const Authorisation getAuthorisationType(int id);
	/*---------------------------------------------*/
	/* Purpose: Searches in a map for the the credit type by the given string and returns its id. (extendable)
	/* Input parameter: A string containing the kind of type. Should be checked in a real program.
	/* Output parameter: An integer representing the credit type.
	/* Global variables in use: a map called types where integer values are mapped to string - no changes
	/*---------------------------------------------*/
	static const int getAuthorisationTypeFromString(std::string name);



private:
	Authorisation authorisation;
	std::string cardNumber;
	std::string retailerName;
	std::string retailerLocation;
};

