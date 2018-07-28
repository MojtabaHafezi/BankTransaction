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
class Cashpoint :
	public Transaction
{
public:
	Cashpoint(std::string pName, Date pDate, double pAmount, std::string plocationId, std::string pCardNumber);
	~Cashpoint();
	/*---------------------------------------------*/
	/* Purpose: Returns a string with the important details about this transaction object.
	/* The identifier of the object is also added through this method.
	/* Output parameter: A string representing this object with space " " as delimiter.
	/*---------------------------------------------*/
	const std::string display();
	const std::string displayWithDelimiter(const char delimiter);
	const std::string getLocationId();
	const std::string getCardNumber();

private:
	std::string locationId;
	std::string cardNumber;
};

