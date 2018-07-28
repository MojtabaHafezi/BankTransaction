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

class DirectDebit :
	public Transaction
{
public:
	DirectDebit(std::string pName, Date pDate, double pAmount, std::string pReferenceNumber);
	~DirectDebit();
	/*---------------------------------------------*/
	/* Purpose: Returns a string with the important details about this transaction object.
	/* The identifier of the object is also added through this method.
	/* Output parameter: A string representing this object with space " " as delimiter.
	/*---------------------------------------------*/
	const std::string display();
	const std::string displayWithDelimiter(const char delimiter);
	const std::string getReferenceNumber();
private:
	std::string referenceNumber;
};

