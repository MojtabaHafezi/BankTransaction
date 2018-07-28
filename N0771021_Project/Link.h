#pragma once
#include "Transaction.h"

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




