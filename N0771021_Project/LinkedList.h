#pragma once
#include "Link.h"
#include <string>
#include <iostream>
template<class F > class LinkedList
{
	friend class TransactionManager;
private:
	Link<F>* header;
	int total;

public:
	LinkedList();
	bool add(F* pTransaction);
	std::string display();
	std::string displayWithDelimiter(const char delimiter);

	void clear();
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

template<class F>
inline std::string LinkedList<F>::displayWithDelimiter(const char delimiter)
{
	Link<F>* temp;
	std::string displayText = "";
	for (temp = header; temp != 0; temp = temp->next)
	{
		displayText += temp->transaction->displayWithDelimiter(delimiter);
		displayText += "\n";
	}
	return displayText;
}


template<class F> std::string LinkedList<F>::display()
{
	Link<F>* temp;
	std::string displayText = "";
	for (temp = header; temp != 0; temp = temp->next)
	{
		displayText += temp->transaction->display();
		displayText += "\n";
	}
	return displayText;
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




