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

void displayMenu();
void insertObject(TransactionManager* ptr);
void deleteObject(TransactionManager* ptr);
void displayObjects(TransactionManager* ptr);
bool saveFile(TransactionManager* ptr);
bool loadFile(TransactionManager* ptr, const char delimiter);
static const char DELIMITER = ' ';

//Helper methods for easier reading 
string getInputFromUser(string message);
bool getIntegerInRange(int value, int min, int max);
const int getValidIntegerFromUser(string message, int min, int max);
const Date getDateFromUser();
Debit::Authorisation getAuthorisationFromUser(string message);
Interest::Type getInterestTypeFromUser(string message);
Creditpoint::Type getCreditTypeFromUser(string message);

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
		//cin.get(choice);
		//choice = _getch();
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
		//cin.get(choice);
		//hoice = _getch();
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
		//cin.get(choice);
		//choice = _getch();
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


int main()
{
	char choice;
	Date time;
	//Attributes required for time measurement
	clock_t start, finish;
	double  duration;

	TransactionManager manager;
	TransactionManager* managerPtr = &manager;
	Debit* debit = new Debit("First", Date(2012, 1, 2, 19, 42, 23), 100.50, "111111", "Morrisons", "Clifton", Debit::MAILORDER);
	Debit* debit2 = new Debit("Bla", Date(2013, 3, 2, 19, 42, 23), 55.23, "232323", "gfgfgfg", "Clifton", Debit::MAILORDER);
	Debit* debit3 = new Debit("Blabla", Date(2012, 1, 4, 19, 52, 23), 100.50, "454545", "dadad", "Clifton", Debit::MAILORDER);
	Cashpoint* cashpoint = new Cashpoint("Second", Date(2007, 1, 2, 19, 42, 23), 66.78, "222222", "64821449325");
	DirectDebit* direct = new DirectDebit("Third", Date(2018, 1, 2, 19, 42, 23), 1458.4478, "14422Wdd");
	Transfer* transfer = new Transfer("Fourth", Date(2017, 3, 2, 19, 42, 23), 92923.23, "19239912", "123123");
	Creditpoint* creditpoint = new Creditpoint("Fifth", Date(2017, 4, 2, 19, 42, 23), 929292.32, Creditpoint::CASH);
	Interest* interest = new Interest("Sixth", Date(2017, 1, 2, 19, 42, 33), 2020.32, Interest::ANNUAL);

	manager.addTransaction(debit);
	manager.addTransaction(cashpoint);
	manager.addTransaction(direct);
	manager.addTransaction(transfer);
	manager.addTransaction(creditpoint);
	manager.addTransaction(interest);
	manager.addTransaction(debit2);
	manager.addTransaction(debit3);
	manager.addTransaction(debit3);
	manager.addTransaction(debit3);

	//MAIN LOOP
	do
	{
		bool valid;
		displayMenu();
		choice = _getch();
		//cin.get(choice);
		cin.ignore(256, '\n');
		switch (toupper(choice))
		{
		case 'I':
			insertObject(managerPtr);
			break;
		case 'D':
			deleteObject(managerPtr);
			break;
		case 'L':
			loadFile(managerPtr, DELIMITER);
			break;
		case 'C':
			displayObjects(managerPtr);
			break;
		case 'N':
			cout << "Please enter the date that should be searched for." << endl;
			start = clock();
			time = getDateFromUser();
			cout << managerPtr->linearSearch(time.getTime());
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << "Time taken: " << duration << endl;
			break;
		case 'M':
			cout << "Please enter the date that should be searched for." << endl;
			start = clock();
			time = getDateFromUser();
			cout << managerPtr->linearSearchAll(time.getTime());
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << "Time taken: " << duration << endl;
			break;
		case 'B':
			cout << "Please enter the date that should be searched for." << endl;
			start = clock();
			time = getDateFromUser();
			cout << managerPtr->binarySearch(time.getTime());
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << "Time taken: " << duration << endl;
			break;
	
		case 'S':
			valid = saveFile(managerPtr);
			if (valid)
				cout << "Data was saved." << endl;
			else
				cout << "Error saving data. Please try again." << endl;
			break;
		case 'T':
			start = clock();
			manager.simpleSort();
			cout << "List was sorted." << endl;
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << "Time taken: " << duration << endl;
			break;
		default:
			break;
		}
	} while (toupper(choice) != 'Q');

	return 0;
}

void displayMenu()
{
	cout << "Menu:" << endl;
	cout << "Press the following key for the specific actions:" << endl;
	cout << "Q/q for quit. Warning: Unsaved data will be lost." << endl;
	cout << "I/i for inserting an object." << endl;
	cout << "D/d for deleting the last added object." << endl;
	cout << "C/c for displaying the contents of all current objects in the list." << endl;
	cout << "S/s for saving the objects." << endl;
	cout << "L/l for loading from a file." << endl;
	cout << "N/n for linear search by date in list." << endl;
	cout << "M/m for linear search with all objects found. " << endl;
	cout << "B/b for binary search by date in list. " << endl;
	cout << "T/t for sorting the list (date in decreasing order)." << endl;
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

		cin.get(choice);
		cin.ignore(256, '\n');
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
	cin.get(choice);
	cin.ignore(256, '\n');
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

	cout << "Enter the filename including the path (without format): " << endl;
	getline(std::cin, fileName);
	bool valid = false;
	char choice;
	cout << "Please choose a format: " << endl;
	cout << "1 for .txt" << endl;
	cout << "2 for .csv" << endl;
	while (!valid)
	{
		//cin.get(choice);
		choice = _getch();
		cin.ignore(256, '\n');
		switch (choice)
		{
		case '1':
			fileName += ".txt";
			valid = true;
			break;
		case '2':
			fileName += ".csv";
			valid = true;
			break;
		default:
			cout << "No valid input. Please enter a valid number!" << endl;
			valid = false;
			break;
		}
	}
	return ptr->saveFile(fileName);

}

bool loadFile(TransactionManager * ptr, const char delimiter)
{
	string fileName;

	cout << "Enter the filename including the path: " << endl;
	getline(std::cin, fileName);
	return ptr->loadFile(fileName, delimiter);
}

