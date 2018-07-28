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
#include "Link.h"
#include <string>
#include <iostream>

//A template linked list class used to create a linked list of any given class that derives from the Transaction class.
/***************************************************************************************
*	 General idea of this implementation from:
*    Title: Lecture 11 Templates
*    Author: Peter FitzGerald
*    Date: 2017
*    Code version: N.A.
*    Availability: Slides from lecture 11
*
***************************************************************************************/
template<class F > class LinkedList
{
	friend class TransactionManager;
private:
	Link<F>* header;
	int total; //A counter to keep track of total amount of inserted objects.

public:
	LinkedList();
	/*---------------------------------------------*/
	/* Purpose:Adds the given object to the list by LIFO principle.
	/* Input parameters: An object that derives from Transaction is required.
	/* Output parameters: A boolean - true if successful, false if any errors occur.
	/* Precondition: Valid transaction object - must derive from Transaction
	/* Postcondition: Object added to the header.
	/*---------------------------------------------*/
	bool add(F* pTransaction);
	/*---------------------------------------------*/
	/* Purpose: Runs through the whole linked list and frees the memory.
	/* Postcondition: All reserved memory is freed. List is empty. No memory leak.
	/*---------------------------------------------*/
	void clear();
	/*---------------------------------------------*/
	/* Purpose: Removes the top object of the list (the one that was added the last).
	/* Output parameters: Boolean - returns if successful
	/* Postcondition: The last added object is deleted from the list again.
	/*---------------------------------------------*/
	bool remove();
	~LinkedList();
	int getSize();
};

//Implementation
#include "LinkedList.h"



template<typename F>
LinkedList<F>::LinkedList()
{
	header = 0;
	total = 0;
}

template<class F>
bool LinkedList<F>::add(F * pTransaction)
{
	Link<F>* temp;
	temp = new Link<F>(pTransaction);
	if (temp == 0)
	{
		return false;
	}
	temp->next = header;
	header = temp;
	total++;
	return true;
}

template<class F> void LinkedList<F>::clear()
{
	Link<F>* temp;
	while (header != 0)
	{
		temp = header;
		header = header->next;
		delete temp;
	}
	total = 0;
}

template<class F> bool LinkedList<F>::remove()
{
	if (header == 0)
		return false;
	else
	{
		Link<F>* temp;
		temp = header;
		header = header->next;
		delete temp;
		total--;
		return true;
	}
}


template<class F> LinkedList<F>::~LinkedList()
{
	clear();
}

template<class F>  int LinkedList<F>::getSize()
{
	return total;
}




