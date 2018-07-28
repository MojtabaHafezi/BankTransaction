// File: Main.cpp
// Version: V2
// Date: 16-12-2017
// Name: Mojtaba Hafezi
// ID: N0771021
// This program provides functionality to store and display a set of Banking Transaction Objects using a Linked List.

/*
Plagiarism Declaration
I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct and dealt with accordingly.
I understand that if I lend this piece of work to another student and they copy all or part of it, either with or
without my knowledge or permission, I shall be guilty of collusion.  In submitting this work, I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.

Name: Mojtaba Hafezi ID No: N0771021
*/


#include "TransactionManager.h"
#include "Debit.h"
#include "Cashpoint.h"
#include "Transaction.h"
#include "DirectDebit.h"
#include "Creditpoint.h"
#include "Transfer.h"
#include "Date.h"
#include "Interest.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>

using namespace std;

/*---------------------------------------------*/
/* Purpose: Shows the menu and the available options to the user.
/* Output parameters: Text-based menu to the standard output
/*---------------------------------------------*/
void displayMenu();
/*---------------------------------------------*/
/* Purpose: Takes the first character of the input a user gives
/*---------------------------------------------*/
void enterKeyForMenu();
/*---------------------------------------------*/
/* Purpose: Takes the input from the user, creates and adds a transaction to the list. Makes use of many helper methods
/* for valid input.
/* Input parameters: Pointer to the TransactionManager.
/* Global variables: LinkedList
/* Postcondition: The given details of the user become a valid transaction object which is added to the list.
/*---------------------------------------------*/
void insertObject(TransactionManager* ptr);
/*---------------------------------------------*/
/* Purpose: Asks the user first if the last transaction should be deleted and does so if confirmed.
/* Input parameters: Pointer to the TransactionManager.
/* Global variables: LinkedList.
/* Postcondition: The last transaction object is deleted from the linkedList.
/*---------------------------------------------*/
void deleteObject(TransactionManager* ptr);
void displayObjects(TransactionManager* ptr); // uses the TransactionManagers method to display all objects
/*---------------------------------------------*/
/* Purpose: Asks the user for the filename + path + the file ending. The input is forwarded to the TransactionManager to save the data
/* into the proper file object. The standard delimiter is " " as given by the test data.
/* Input parameters: Pointer to the TransactionManager
/* Precondition: Valid filename
/* Postcondition: The data of the current linkedList is added to the specific file object
/* Output parameters: Boolean - returns true if there were no errors during the whole process.
/*---------------------------------------------*/
bool saveFile(TransactionManager* ptr);
/*---------------------------------------------*/
/* Purpose: Asks the user for the filename + path but without the file ending. Afterwards the user is prompted to
/* choose the file type (txt or csv). Depending on the decision the delimiter is chosen and the function is forwarded
/* to the TransactionManager to save the data.
/* Input parameters: Pointer to the TransactionManager
/* Precondition: Valid filename
/* Postcondition: The data of the current linkedList is added to the specific file object
/* Output parameters: Boolean - returns true if there were no errors during the whole process.
/*---------------------------------------------*/
bool saveFileWithDelimiter(TransactionManager* ptr);
/*---------------------------------------------*/
/* Purpose: Asks the user for the filename and loads the given data from the file by forwarding it to the TransactionManager.
/* Input parameters: Pointer to the TransactionManager
/* Precondition: Valid filename
/* Output parameters: Boolean - returns true if there were no errors during the whole process.
/*---------------------------------------------*/
bool loadFile(TransactionManager* ptr, const char delimiter);
/*---------------------------------------------*/
/* Purpose: Runs a test series with specific tests.
/* Input parameters: Pointer to the TransactionManager
/* Output parameters: String - containing the complete test result
/*---------------------------------------------*/
string testPlan(TransactionManager* ptr);


static const char DELIMITER = ' '; //only global variable used since the test data only contains this character.

//Helper methods for easier reading and following the DRY principle

/*---------------------------------------------*/
/* Purpose: Asks the user for a specific input. Can be used generally to get strings from user.
/* Input parameters: String - prompts the user to do something specific
/* Output parameters: String containing the information required
/*---------------------------------------------*/
string getInputFromUser(string message);
/*---------------------------------------------*/
/* Purpose: Determines if a given value is between a specific range. Used as a helper method.
/* Input parameters: int value, int min, int max
/* Output parameters: Boolean - true if the value is in range between min and max
/*---------------------------------------------*/
bool getIntegerInRange(int value, int min, int max);
/*---------------------------------------------*/
/* Purpose: Prompts the user to enter a specific integer value and confirms that the value is in a specific range. Used as a helper method.
/* Input parameters: String message, int min, int max
/* Output parameters: Integer
/*---------------------------------------------*/
const int getValidIntegerFromUser(string message, int min, int max);
/*---------------------------------------------*/
/* Purpose: Prompts the user for input for a specific date. The method uses other helper methods to make sure
/* that each value is valid. The given values are used to create a Date object.
/* Output parameters: Date
/*---------------------------------------------*/
const Date getDateFromUser();
/*---------------------------------------------*/
/* Purpose: These methods provide the user a choice for the specific type. The user needs to enter a valid input
/* before the program continues.
/* Input parameter: String message.
/* Output parameters: Specific type
/*---------------------------------------------*/
Debit::Authorisation getAuthorisationFromUser(string message);
Interest::Type getInterestTypeFromUser(string message);
Creditpoint::Type getCreditTypeFromUser(string message);
/*---------------------------------------------*/
/* Purpose: Helps for easier output during test phase
/* Input parameter: int:test number, string:method being tested, string:action taken, string: input, string: expected output
/* string: actual output, bool: success or fail, char: delimiter used to seperate the string
/* Output parameters: String with the results of the test
/*---------------------------------------------*/
string testOutput(int test, string method, string action, string input, string eoutput, string aoutput, bool fail, char dl);



void displayMenu()
{
	cout << "Menu:" << endl;
	cout << "Press the following key for the specific actions:" << endl;
	cout << "Q/q for quit. Warning: Unsaved data will be lost." << endl;
	cout << "I/i for inserting an object." << endl;
	cout << "D/d for deleting the last added object." << endl;
	cout << "C/c for displaying the contents of all current objects in the list." << endl;
	cout << "S/s for saving the objects." << endl;
	cout << "X/x for saving the transaction objects with a specific delimiter." << endl;
	cout << "L/l for loading from a file." << endl;
	cout << "N/n for linear search by date in list." << endl;
	cout << "M/m for linear search with all objects found. " << endl;
	cout << "B/b for binary search by date in list. " << endl;
	cout << "T/t for sorting the list (date in decreasing order)." << endl;
	cout << "P/p for running the test plan." << endl;
}

void enterKeyForMenu()
{
	cout << "Please enter any key for returning to the menu." << endl;
	_getch();
}

void insertObject(TransactionManager *ptr)
{
	bool valid = false;
	while (!valid)
	{
		//get type of transaction
		char choice;
		cout << "Enter the type of banking object." << endl;
		cout << "1 for Debit" << endl;
		cout << "2 for Cashpoint" << endl;
		cout << "3 for DirectDebit" << endl;
		cout << "4 for Transfer" << endl;
		cout << "5 for Creditpoint" << endl;
		cout << "6 for Interest" << endl;
		cout << "q for cancel" << endl;
		//attributes all have in common - DRY principle
		string name;
		Date date;
		double amount;
		string string1;
		string string2;
		string string3;
		Debit::Authorisation authType;
		Creditpoint::Type creditType;
		Interest::Type  interestType;

		choice = _getch();
		//cin.get(choice);
		//cin.ignore(256, '\n');
		switch (choice)
		{
		case '1':
			cout << "Debit was chosen." << endl;
			name = "Debit";
			date = getDateFromUser();
			amount = stod(getInputFromUser("Please enter the amount: "));
			string1 = getInputFromUser("Please enter the card number: ");
			string2 = getInputFromUser("Please enter the name of the retailer: ");
			string3 = getInputFromUser("Please enter the name of the location:");
			authType = getAuthorisationFromUser("Choose the authorisation type of the transaction.");
			ptr->addTransaction(new Debit(name, date, amount, string1, string2, string3, authType));
			valid = true;
			break;
		case '2':
			cout << "Cashpoint was chosen." << endl;
			name = "Cashpoint";
			date = getDateFromUser();
			amount = stod(getInputFromUser("Please enter the amount: "));
			string1 = getInputFromUser("Please enter the location ID: ");
			string2 = getInputFromUser("Please enter the card number: ");
			ptr->addTransaction(new Cashpoint(name, date, amount, string1, string2));
			valid = true;
			break;
		case '3':
			cout << "Direct debit was chosen." << endl;
			name = "DirectDebit";
			date = getDateFromUser();
			amount = stod(getInputFromUser("Please enter the amount: "));
			string1 = getInputFromUser("Please enter the reference number: ");
			ptr->addTransaction(new DirectDebit(name, date, amount, string1));
			valid = true;
			break;
		case '4':
			cout << "Transfer was chosen." << endl;
			name = "Transfer";
			date = getDateFromUser();
			amount = stod(getInputFromUser("Please enter the amount: "));
			string1 = getInputFromUser("Please enter the account number: ");
			string2 = getInputFromUser("Please enter the sort number: ");
			ptr->addTransaction(new Transfer(name, date, amount, string1, string2));
			valid = true;
			break;
		case '5':
			cout << "Creditpoint was chosen." << endl;
			name = "CreditPoint";
			date = getDateFromUser();
			amount = stod(getInputFromUser("Please enter the amount: "));
			creditType = getCreditTypeFromUser("Choose the credit type for the transaction: ");
			ptr->addTransaction(new Creditpoint(name, date, amount, creditType));
			valid = true;
			break;
		case '6':
			cout << "Interest was chosen." << endl;
			name = "Interest";
			date = getDateFromUser();
			amount = stod(getInputFromUser("Please enter the amount: "));
			interestType = getInterestTypeFromUser("Choose the interest type for the transaction: ");
			ptr->addTransaction(new Interest(name, date, amount, interestType));
			valid = true;
			break;
		case 'q':
			cout << "Cancelled." << endl;
			valid = true;
			break;
		default:
			cout << "Please enter a valid input" << endl;
			valid = false;
			break;
		}
	}
}

void deleteObject(TransactionManager* ptr)
{
	char choice;
	cout << "Are you sure you want to delete the first object in the list? Enter 1 for yes, 2 for no." << endl;
	choice = _getch();
	//cin.get(choice);
	//cin.ignore(256, '\n');
	if (choice == '1')
	{
		ptr->removeTransaction();
		displayObjects(ptr);
	}
}

void displayObjects(TransactionManager* ptr)
{
	cout << "List of all current objects: " << endl;
	cout << ptr->displayAllTransactions() << endl;
}

bool saveFile(TransactionManager * ptr)
{
	string fileName;
	cout << "Enter the filename including the path: " << endl;
	getline(std::cin, fileName);
	return ptr->saveFile(fileName);
}

bool saveFileWithDelimiter(TransactionManager * ptr)
{
	string fileName;
	char delimiter;
	cout << "Enter the filename including the path (without format): " << endl;
	getline(std::cin, fileName);
	bool valid = false;
	char choice;
	cout << "Please choose a format: " << endl;
	cout << "1 for .txt" << endl;
	cout << "2 for .csv" << endl;
	while (!valid)
	{
		choice = _getch();
		//cin.ignore(256, '\n');
		switch (choice)
		{
		case '1':
			fileName += ".txt";
			delimiter = ' ';
			valid = true;
			break;
		case '2':
			fileName += ".csv";
			delimiter = ';';
			valid = true;
			break;
		default:
			cout << "No valid input. Please enter a valid number!" << endl;
			valid = false;
			break;
		}
	}
	return ptr->saveFileWithDelimiter(fileName, delimiter);
}

bool loadFile(TransactionManager * ptr, const char delimiter)
{
	string fileName;
	cout << "Enter the filename including the path: " << endl;
	getline(std::cin, fileName);
	return ptr->loadFile(fileName, delimiter);
}

string testPlan(TransactionManager* ptr)
{
	const char DELIMITER = ';';
	bool valid;
	int size;
	string testOutput(int test, string method, string action, string input, string eoutput, string aoutput, bool fail, char dl);
	string result = "";
	//*****Test phase 1: Creation, initialisation of transaction objects and basic functionalities with the list.****

	//#1: Creation of transaction objects.
	Debit* debit = new Debit("Debit", Date(2011, 1, 2, 19, 42, 23), 100.50, "111111", "Morrisons", "Clifton", Debit::MAILORDER);
	Cashpoint* cashpoint = new Cashpoint("Cashpoint", Date(2017, 1, 2, 19, 42, 23), 66.78, "222222", "64821449325");
	DirectDebit* direct = new DirectDebit("DirectDebit", Date(2017, 1, 2, 19, 42, 23), 1458.4478, "14422Wdd");
	Transfer* transfer = new Transfer("Transfer", Date(2015, 1, 2, 19, 42, 23), 92923.23, "19239912", "123123");
	Creditpoint* creditpoint = new Creditpoint("Creditpoint", Date(2016, 1, 2, 19, 42, 23), 929292.32, Creditpoint::CASH);
	Interest* interest = new Interest("Interest", Date(2017, 1, 2, 19, 42, 33), 2020.32, Interest::ANNUAL);
	result += testOutput(1, "Constructors", "Initialisation of each different transaction object", "Valid values for each object", "N.a.", "N.a.", 1, DELIMITER);

	//#2: Check if the list is empty
	size = ptr->getSize();
	result += testOutput(2, "getSize", "Check if the list of the Manager is empty", "N.a.", "0", to_string(size), (size == 0), DELIMITER);

	//#3: Add transactions to the list
	ptr->addTransaction(debit);
	ptr->addTransaction(cashpoint);
	ptr->addTransaction(direct);
	ptr->addTransaction(transfer);
	ptr->addTransaction(creditpoint);
	valid = ptr->addTransaction(interest);
	// after the transactions were added to the list, the list mustn't be empty.
	result += testOutput(3, "addTransaction", "Check if the objects were added to the list", "different transaction objects", "n.a.", "n.a.", valid, DELIMITER);
	size = ptr->getSize();
	// calling the display for each object in the list to see successful transaction
	result += ptr->displayAllTransactions();
	// Using the getSize() method to return the number of elements in the list.
	result += testOutput(3, "getSize", "Check if the list of the Manager is empty", "N.a.", "6", to_string(size), (size == 6), DELIMITER);

	//#4: Removing last transaction
	valid = ptr->removeTransaction();
	result += testOutput(4, "removeTransaction", "Check if the last object was removed from list", "N.a.", "true(1)", to_string(valid), valid, DELIMITER);
	result += ptr->displayAllTransactions(); // the last object added was of kind interest - display shows it was removed
	size = ptr->getSize();
	result += testOutput(4, "getSize()", "List should be 1 less in size", "N.a.", "size of 5", to_string(size), size == 5, DELIMITER);

	//#5: Linear Search by date
	string debitDetails = debit->display() + "\n";
	string resultByLinearSearch = ptr->linearSearch(debit->getTime());
	//checking for equality using the compare of the string library. If the result equals 0 then the strings are equal.
	result += testOutput(5, "linearSearch", "Linear search for first object matching the time", "debit->getTime()", "n.a.", "n.a.", debitDetails.compare(resultByLinearSearch) == 0, DELIMITER);

	//#6: Linear Search by date for all objects - runs through the linked list and adds the details of all objects with the same date
	//first the debit object is added a second time to the TransactionManager. Now the result must return 2 found objects.
	valid = ptr->addTransaction(debit);
	string resultByLinearSearchAll = ptr->linearSearchAll(debit->getTime());
	//Since the search returns the details from display with an additional "\n" the resulting string must be the same
	debitDetails += "\n" + debit->display() + "\n";
	result += testOutput(6, "linearSearchAll", "Linear search for all objects matching the time", "debit->getTime()", "n.a.", "n.a.", debitDetails.compare(resultByLinearSearchAll) == 0, DELIMITER);
	ptr->removeTransaction(); // removing last debit object again for next search

	//#7: Sorting the list by date -

	result += testOutput(7, "simpleSort", "Sorting all objects by date", "n.a.", "n.a.", "n.a.", 1, DELIMITER);

	result += ptr->displayAllTransactions();
	ptr->simpleSort();
	result += "SORTED \n";
	result += ptr->displayAllTransactions();

	//#8: Binary Search - precondition: sorted list
	debitDetails = debit->display() + "\n";
	string resultByBinarySearch = ptr->binarySearch(debit->getTime());
	result += testOutput(8, "binarySearch", "Searching for first object with given date", "n.a.", "n.a.", "n.a.", debitDetails.compare(resultByBinarySearch) == 0, DELIMITER);


	//#9: Save File - Saves the complete list with specific delimiter or standard delimiter into a file (delimiter was not in requirements)
	valid = ptr->saveFile("testOutput1.txt");
	result += testOutput(9, "saveFile", "Saves the list into a file object", "n.a.", "true (=1)", to_string(valid), valid == true, DELIMITER);
	valid = ptr->saveFileWithDelimiter("testOutputWithDelimiter.csv", DELIMITER);
	result += testOutput(9, "saveFileWithDelimiter", "Saves the list into a file object with specific delimiter", "n.a.", "true (=1)", to_string(valid), valid == true, DELIMITER);

	//#10: Load File - Loads data from a text file - delimiter can be chosen depending on the specification
	string filename = "testOutput1.txt";
	valid = ptr->loadFile(filename, ' '); //standard delimiter is a space
	result += testOutput(10, "loadFile", "Loads the data from an object file", "n.a.", "true (=1)", to_string(valid), valid == true, DELIMITER);
	size = ptr->getSize();
	result += testOutput(10, "loadFile", "Loads the data from an object file", "n.a.", "size > 6", to_string(size), size >= 6, DELIMITER);
	result += ptr->displayAllTransactions();

	//#11: Clear transactions - clears the whole list, no data should be available afterwards.
	valid = ptr->clearTransactions();
	result += testOutput(11, "clearTransactions", "Empties the whole list", "n.a.", "true (=1)", to_string(valid), valid == true, DELIMITER);
	result += "Size of list after clear: " + to_string(ptr->getSize()) + "\n";
	result += "Displaying current list: " + ptr->displayAllTransactions();

	//Test phase 3: Further tests for binary search and sort 
	Debit* debit2 = new Debit("Debit", Date(2012, 5, 2, 19, 42, 23), 100.50, "124588d5", "Debit2", "City", Debit::MAILORDER);
	Cashpoint* cashpoint2 = new Cashpoint("Cashpoint", Date(2001, 1, 7, 19, 42, 23), 6.78, "988766", "Cashpoint2");
	DirectDebit* direct2 = new DirectDebit("DirectDebit", Date(2007, 14, 2, 49, 42, 23), 158.4478, "direct2");
	Transfer* transfer2 = new Transfer("Transfer", Date(2005, 1, 4, 19, 52, 23), 92923.23, "19239912", "trnasfer2");
	Creditpoint* creditpoint2 = new Creditpoint("Creditpoint", Date(2006, 1, 2, 19, 42, 23), 9292.32, Creditpoint::CASH);
	Interest* interest2 = new Interest("Interest", Date(2010, 1, 2, 19, 42, 13), 204, Interest::ANNUAL);
	ptr->addTransaction(debit2);
	ptr->addTransaction(cashpoint2);
	ptr->addTransaction(direct2);
	ptr->addTransaction(transfer2);
	ptr->addTransaction(creditpoint2);
	ptr->addTransaction(interest2);
	ptr->simpleSort();
	result += "New tests with new data: \n";
	result += ptr->binarySearch(debit2->getTime());
	result += ptr->binarySearch(cashpoint2->getTime());
	result += ptr->binarySearch(direct2->getTime());
	result += ptr->binarySearch(transfer2->getTime());
	result += ptr->binarySearch(creditpoint2->getTime());
	result += ptr->binarySearch(interest2->getTime());
	result += "New test after clear: \n";
	ptr->clearTransactions();
	ptr->addTransaction(debit2);
	ptr->addTransaction(cashpoint2);
	ptr->addTransaction(direct2);
	ptr->addTransaction(transfer2);
	ptr->addTransaction(creditpoint2);
	ptr->addTransaction(interest2);
	ptr->simpleSort();
	result += ptr->binarySearch(debit2->getTime());
	result += ptr->binarySearch(cashpoint2->getTime());
	result += ptr->binarySearch(direct2->getTime());
	result += ptr->binarySearch(transfer2->getTime());
	result += ptr->binarySearch(creditpoint2->getTime());
	result += ptr->binarySearch(interest2->getTime());
	result += "\n" + ptr->displayAllTransactions();


	return result;
}

string getInputFromUser(string message)
{
	string input = "";
	cout << message << endl;
	cin >> input;
	return input;
}

bool getIntegerInRange(int value, int min, int max)
{
	return (value >= min && value <= max);
}

const int getValidIntegerFromUser(string message, int min, int max)
{
	int value;
	bool valid = false;
	while (!valid)
	{
		value = stoi(getInputFromUser(message));
		if (getIntegerInRange(value, min, max))
			valid = true;
		else
			cout << "Please enter a valid input between " << to_string(min) << " and " << to_string(max) << endl;
	}
	return value;
}

const Date getDateFromUser()
{
	int day, month, year, hour, min, sec;
	day = getValidIntegerFromUser("Please enter the day value: ", 1, 31);
	month = getValidIntegerFromUser("Please enter the month value: ", 1, 12);
	year = getValidIntegerFromUser("Please enter the year value: ", 1900, 2100);
	hour = getValidIntegerFromUser("Please enter the hour value: ", 0, 23);
	min = getValidIntegerFromUser("Please enter the minute value: ", 0, 59);
	sec = getValidIntegerFromUser("Please enter the seconds value: ", 0, 59);
	Date date(year, month, day, hour, min, sec);
	return date;
}

Debit::Authorisation getAuthorisationFromUser(string message)
{
	Debit::Authorisation auth;
	bool valid = false;
	int choice;
	cout << message << endl;
	cout << "1 for Online" << endl;
	cout << "2 for Phone" << endl;
	cout << "3 for Mail" << endl;
	//get input until valid
	while (!valid)
	{
		cin >> choice;
		cin.ignore(256, '\n');
		if (getIntegerInRange(choice, 1, 3))
		{
			auth = Debit::getAuthorisationType(choice);
			valid = true;
		}
		else
			cout << "Please enter a valid number between 1 and 3" << endl;
	}
	return auth;
}

Interest::Type getInterestTypeFromUser(string message)
{
	bool valid = false;
	int choice;
	Interest::Type type;
	cout << message << endl;
	cout << "1 for Daily" << endl;
	cout << "2 for Monthly" << endl;
	cout << "3 for Annually" << endl;

	while (!valid)
	{
		cin >> choice;
		cin.ignore(256, '\n');
		if (getIntegerInRange(choice, 1, 3))
		{
			type = Interest::getInterestType(choice);
			valid = true;
		}
		else
			cout << "Please enter a valid number between 1 and 3" << endl;
	}
	return type;
}

Creditpoint::Type getCreditTypeFromUser(string message)
{
	bool valid = false;
	int choice;
	Creditpoint::Type type;

	cout << message << endl;
	cout << "1 for Cheque" << endl;
	cout << "2 for Cash" << endl;
	while (!valid)
	{
		cin >> choice;
		cin.ignore(256, '\n');
		if (getIntegerInRange(choice, 1, 2))
		{
			type = Creditpoint::getCreditpointType(choice);
			valid = true;
		}
		else
			cout << "Please enter a valid number between 1 and 2" << endl;
	}
	return type;
}

string testOutput(int test, string method, string action, string input, string eoutput, string aoutput, bool fail, char dl)
{
	string result = "";
	result += method;
	result += dl;
	result += action;
	result += dl;
	result += input;
	result += dl;
	result += eoutput;
	result += dl;
	result += aoutput;
	result += dl;
	result += to_string(fail);
	result += "\n";
	return result;
}


/***************************************************************************************
*	 Basic idea of the implementation for the timing from:
*    Title: Clock (Lecture 11)
*    Author: Peter FitzGerald
*    Date: 2017
*    Code version: N.A.
*    Availability: Slides from Lecture 11
***************************************************************************************/
int main()
{
	char choice;
	Date time;
	//Attributes required for time measurement
	clock_t start, finish;
	double  duration;
	//TransactionManager instance. 
	TransactionManager manager;
	TransactionManager* managerPtr = &manager;


	//MAIN LOOP
	do
	{
		bool valid;
		displayMenu();
		choice = _getch();
		//cin.ignore(256, '\n');
		switch (toupper(choice))
		{
		case 'I':
			insertObject(managerPtr);
			enterKeyForMenu();
			break;
		case 'D':
			deleteObject(managerPtr);
			enterKeyForMenu();
			break;
		case 'L':
			loadFile(managerPtr, DELIMITER);
			enterKeyForMenu();
			break;
		case 'C':
			displayObjects(managerPtr);
			enterKeyForMenu();
			break;
		case 'N':
			cout << "Please enter the date that should be searched for." << endl;
			time = getDateFromUser();
			start = clock();
			cout << managerPtr->linearSearch(time.getTime());
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << "Time taken: " << duration << endl;
			enterKeyForMenu();
			break;
		case 'M':
			cout << "Please enter the date that should be searched for." << endl;
			start = clock();
			time = getDateFromUser();
			cout << managerPtr->linearSearchAll(time.getTime());
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << "Time taken: " << duration << endl;
			enterKeyForMenu();
			break;
		case 'B':
			cout << "Please enter the date that should be searched for." << endl;
			time = getDateFromUser();
			start = clock();
			cout << managerPtr->binarySearch(time.getTime());
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << "Time taken: " << duration << endl;
			enterKeyForMenu();
			break;
		case 'S':
			valid = saveFile(managerPtr);
			if (valid)
				cout << "Data was saved." << endl;
			else
				cout << "Error saving data. Please try again." << endl;
			enterKeyForMenu();
			break;
		case 'X':
			valid = saveFileWithDelimiter(managerPtr);
			if (valid)
				cout << "Data was saved." << endl;
			else
				cout << "Error saving data. Please try again." << endl;
			enterKeyForMenu();
			break;
		case 'T':
			start = clock();
			manager.simpleSort();
			cout << "List was sorted." << endl;
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << "Time taken: " << duration << endl;
			enterKeyForMenu();
			break;
		case 'P':
			cout << testPlan(managerPtr);
			break;
		default:
			break;
		}
	}
	while (toupper(choice) != 'Q');

	return 0;
}
