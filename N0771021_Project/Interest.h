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

class Interest :
	public Transaction
{
public:
	enum Type { DAILY, MONTHLY, ANNUAL };
	Interest(std::string pName, Date pDate, double pAmount, Type pType);
	~Interest();
	/*---------------------------------------------*/
	/* Purpose: Returns a string with the important details about this transaction object.
	/* The identifier of the object is also added through this method.
	/* Output parameter: A string representing this object with space " " as delimiter.
	/*---------------------------------------------*/
	const std::string display();
	const std::string displayWithDelimiter(const char delimiter);
	/*---------------------------------------------*/
	/* Purpose: Uses a switch statement to determine the type and returns a string representing the type.
	/* Output parameter: Returns a string containing the type.
	/*---------------------------------------------*/
	const std::string getType();
	/*---------------------------------------------*/
	/* Purpose: Determines the type of interest and returns it
	/* Input parameter: Id of the type. Should be checked in a real program.
	/* Output parameter: returns which kind of interest type this object has.
	/*---------------------------------------------*/
	static const Type getInterestType(int id);
	/*---------------------------------------------*/
	/* Purpose: Searches in a map for the the interest type by the given string and returns its id. (extendable)
	/* Input parameter: A string containing the kind of type. Should be checked in a real program.
	/* Output parameter: An integer representing the interest type.
	/* Global variables in use: a map called types where integer values are mapped to string - no changes
	/*---------------------------------------------*/
	static const int getInterestTypeFromString(std::string name);
private:
	Type type;
};

