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
#include "LinkedList.h"
#include <fstream>
#include <string>
#include "Transaction.h"
#include "Cashpoint.h"
#include "Debit.h"
#include "Date.h"
#include "Creditpoint.h"
#include "Interest.h"
#include "DirectDebit.h"
#include "Transfer.h"

class TransactionManager
{
	LinkedList<Transaction> linkedList;
public:
	/* Purpose:Adds the given object to the list by LIFO principle.
	/* Input parameters: An object that derives from Transaction is required.
	/* Output parameters: A boolean - true if successful, false if any errors occur.
	/* Precondition: Valid transaction object - must derive from Transaction
	/* Postcondition: Obect added to the linkedList of this class
	/*---------------------------------------------*/
	bool addTransaction(Transaction* pTransaction);
	/*---------------------------------------------*/
	/* Purpose: Removes the top object of the list (the one that was added the last).
	/* Output parameters: Boolean - returns if successful
	/* Postcondition: The last added object is deleted from the list again.
	/*---------------------------------------------*/
	bool removeTransaction();
	/*---------------------------------------------*/
	/* Purpose: Returns a list of all the objects in the linked list with details. Seperated by a new line after each object. LIFO
	/* Output parameters: String
	/*---------------------------------------------*/
	const std::string displayAllTransactions();
	const std::string displayAllTransactionsWithDelimiter(const char delimiter);
	/*---------------------------------------------*/
	/* Purpose: Returns an integer representing the number of objects currently available in the linkedList.
	/* Output parameters: Integer
	/*---------------------------------------------*/
	const int getSize();
	/*---------------------------------------------*/
	/* Purpose: Searches in a map for the the transaction type by the given string and returns its id. (extendable)
	/* Input parameter: A string containing the kind of type. Should be checked in a real program.
	/* Output parameter: An integer representing the transaction type.
	/* Global variables in use: a map called types where integer values are mapped to string - no changes
	/*---------------------------------------------*/
	const int getTransactionType(std::string identifier);
	/*---------------------------------------------*/
	/* Purpose: Sorts all elements in the linkedList by ascending order. The comparison takes the time
	/* of the transaction objects in seconds (starting from 1st Jan 1900 until the given time of the transaction object).
	/* The algorithm used is an implementation of Bubble Sort. Big O complexity of O(n*n) in average or worst case or O(n) in best case.
	/* Global variables in use: linkedList - a list containing all the Links
	/* Postcondition: If there is more than one element in the list then the list gets sorted.
	/*---------------------------------------------*/
	void simpleSort();
	/*---------------------------------------------*/
	/* Purpose: Searches the linkedList for an object with the given time. Returns a string containing the details of the very first object
	/* found or a notification that there was no data to the given time. The algorithm used is a simple linear search.
	/* Input parameters: The time with type time_t - used to calculate time in seconds					                       
	/* Output parameters: String - the display method of the transaction object is called
	/*---------------------------------------------*/
	const std::string linearSearch(time_t pTime);
	/*---------------------------------------------*/
	/* Purpose: Searches the linkedList for all objects with the given time. Returns a string containing the details of all objects
	/* found or a notification that there was no data to the given time. The algorithm used is a simple linear search.
	/* Input parameters: The time with type time_t - used to calculate time in seconds
	/* Output parameters: String - the display methods of the transaction objects get called
	/*---------------------------------------------*/
	const std::string linearSearchAll(time_t pTime);
	/*---------------------------------------------*/
	/* Purpose: Searches the linkedList for an object with the given time. Returns a string containing the details of the very first object
	/* found or a notification that there was no data to the given time. The algorithm used is a simple binary search.
	/* Input parameters: The time with type time_t - used to calculate time in seconds
	/* Output parameters: String - the display method of the transaction object is called
	/*---------------------------------------------*/
	const std::string binarySearch(time_t pTime);
	/*---------------------------------------------*/
	/* Purpose: Opens the file object associated with the given filename and writes all the data of the linkedList into it.
	/* By default the data is appended and not overwritten. The standard delimiter is " " as given by the test data.
	/* Input parameters: String - the filename of the file to be opened
	/* Precondition: Valid filename, sorted linkedList
	/* Postcondition: The data of the current linkedList is added to the specific file object
	/* Output parameters: Boolean - returns true if there were no errors upon opening and writing the file
	/*---------------------------------------------*/
	bool saveFile(const std::string fileName);
	bool saveFileWithDelimiter(const std::string fileName, const char delimiter);
	/*---------------------------------------------*/
	/* Purpose: Opens the file object associated with the given filename and adds all transaction objects into the linkedList.
	/* Uses specific delimiter for finding the correct data sets, each new line is a new transaction object. No exception handling and
	/* error handling available in this method although it is strongly recommended for a real program in use.
	/* Input parameters: Valid filename and specific delimiter 
	/* Output parameters: Boolean - returns true if the file was loaded without errors and closed at the end of operation
	/* Precondition: Valid filename, correct delimiter (fitting to file object)
	/* Postcondition: LinkedList has all the transaction objects added
	/* Global variables in use: LinkedList
	/*---------------------------------------------*/
	bool loadFile(const std::string fileName, const char delimiter);
	/*---------------------------------------------*/
	/* Purpose: Clears the linkedList in this class.
	/* Output parameters: Boolean - returns true if the header == 0
	/*---------------------------------------------*/
	bool clearTransactions();
	TransactionManager();

	~TransactionManager();
};

