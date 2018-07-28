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

//A template class used for the links in a linked list. 
/***************************************************************************************
*	 General idea of this implementation from:
*    Title: Lecture 11 Templates
*    Author: Peter FitzGerald
*    Date: 2017
*    Code version: N.A.
*    Availability: Slides from lecture 11
*
***************************************************************************************/
template<class F> class LinkedList;
template<class F> class Link
{
	friend class LinkedList<F>;
	friend class TransactionManager;
private:
	Link<F>* next;
	F* transaction;

public:
	Link(F* pTransaction);
	~Link();

};

//Implementation


template<class F>
Link<F>::Link(F * pTransaction)
{
	transaction = pTransaction;
	next = 0;
}


template<class F>
Link<F>::~Link()
{
	//delete transaction;
}




