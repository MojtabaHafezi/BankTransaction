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

//Map that maps a string to an integer. Used to find the relevant transaction object type.
static const std::map<std::string, int> types
{
	{ "DB", 1 },
	{ "CSP", 2 },
	{ "DD", 3 },
	{ "TR", 4 },
	{ "CDP", 5 },
	{ "INT", 6 }
};


bool TransactionManager::addTransaction(Transaction * pTransaction)
{
	return linkedList.add(pTransaction);
}

bool TransactionManager::removeTransaction()
{
	return linkedList.remove();
}

const std::string TransactionManager::displayAllTransactions()
{
	Link<Transaction>* temp;
	std::string displayText = "";
	if (getSize() > 0)
		for (temp = linkedList.header; temp != 0; temp = temp->next)
		{
			displayText += temp->transaction->display();
			displayText += "\n";
		}
	else
		displayText += "No data available. \n";
	return displayText;
}

const std::string TransactionManager::displayAllTransactionsWithDelimiter(const char delimiter)
{
	Link<Transaction>* temp;
	std::string displayText = "";
	for (temp = linkedList.header; temp != 0; temp = temp->next)
	{
		displayText += temp->transaction->displayWithDelimiter(delimiter);
		displayText += "\n";
	}
	return displayText;
}

const int TransactionManager::getSize()
{
	return linkedList.getSize();
}

/***************************************************************************************
*	 General idea of this implementation from:
*    Title: how can I map an int to a corresponding string in C/C++
*    Author: R Samuel Klatchko
*    Date: 2017
*    Code version: N.A.
*    Availability:https://stackoverflow.com/questions/1910733/how-can-i-map-an-int-to-a-corresponding-string-in-c-c
*
***************************************************************************************/
const int TransactionManager::getTransactionType(std::string identifier)
{
	auto search = types.find(identifier);
	if (search != types.end())
		return search->second;
	else
		return -1;
}


/***************************************************************************************
*	 Basic idea of the implementation from:
*    Title: Function Templates (Slide 4)
*    Author: Peter FitzGerald
*    Date: 2017
*    Code version: N.A.
*    Availability: Slides from Lecture 11
*	 Strongly changed due to the fact that it is a linked list and not an array.
***************************************************************************************/
void TransactionManager::simpleSort()
{
	std::cout << "Sorting list..." << std::endl;
	Link<Transaction>* temp;
	Link<Transaction>* temp2;
	Link<Transaction>* previous;
	bool sortable = true;

	if (linkedList.header == 0)
		return;

	for (int i = 0; i < linkedList.getSize(); i++) //first loop
	{
		if (!sortable) //break out of loop if there are no elements left to sort
			return;
		sortable = false;
		temp = previous = linkedList.header;
		do //second loop
		{
			if (temp == linkedList.header && temp->transaction->getTime() < temp->next->transaction->getTime())
			{
				temp2 = temp->next;
				temp->next = temp2->next;
				temp2->next = temp;
				linkedList.header = temp2;
				sortable = true;
			}
			else
				if (temp->next != 0 && temp->transaction->getTime() < temp->next->transaction->getTime())
				{
					//SWAP THE DATA - previous link needed
					previous->next = temp->next;
					temp->next = temp->next->next;
					previous->next->next = temp;
					sortable = true;
				}
			previous = temp;
			temp = temp->next;
		}
		while (temp != 0);
	}
}
/***************************************************************************************
*	 Basic idea of the implementation from:
*    Title: Linear search
*    Author: Peter FitzGerald
*    Date: 2017
*    Code version: N.A.
*    Availability: Slides from Lecture 11
***************************************************************************************/
const std::string TransactionManager::linearSearch(time_t pTime)
{
	Link<Transaction>* temp;
	for (temp = linkedList.header; temp != 0; temp = temp->next)
	{
		if (temp->transaction->getTime() == pTime)
			return temp->transaction->display() + "\n";
	}
	return "No data found.\n";
}

/***************************************************************************************
*	 Basic idea of the implementation from:
*    Title: Linear search
*    Author: Peter FitzGerald
*    Date: 2017
*    Code version: N.A.
*    Availability: Slides from Lecture 11
***************************************************************************************/
const std::string TransactionManager::linearSearchAll(time_t pTime)
{
	bool valid = false;
	std::string result = "";
	Link<Transaction>* temp;
	for (temp = linkedList.header; temp != 0; temp = temp->next)
	{
		if (temp->transaction->getTime() == pTime)
		{
			result += temp->transaction->display() + "\n";
			valid = true;
		}
	}
	if (valid)
		return result;
	else
		return "No data found.\n";
}

/***************************************************************************************
*	 Basic idea of the implementation from:
*    Title: Binary search
*    Author: Peter FitzGerald
*    Date: 2017
*    Code version: N.A.
*    Availability: Slides from Lecture 11
***************************************************************************************/
const std::string TransactionManager::binarySearch(time_t pTime)
{

	int low = 0;
	int high = linkedList.getSize() - 1;
	int middle = (low + high + 1) / 2;
	int counter = 0;
	bool required = false; // this flag is required so that the counter doesn't start from 0 again else temp = null before end 
	Link<Transaction>* temp = linkedList.header;
	while (low <= high)
	{
		if (required)
			counter = 0;
		while (counter < middle)
		{
			if (temp)
				temp = temp->next;
			counter++;
		}

		if (temp->transaction->getTime() == pTime)
			return temp->transaction->display() + "\n";
		else
			if (pTime > temp->transaction->getTime())
			{
				high = middle - 1;
				temp = linkedList.header;
				required = true;
			}
			else
			{
				low = middle + 1;
				required = false;
			}

		middle = (low + high + 1) / 2;
	}
	return "No data found. \n";

}




bool TransactionManager::saveFile(const std::string fileName)
{
	std::ofstream dataOut;
	dataOut.open(fileName, std::fstream::app);
	if (!dataOut)
	{
		std::cerr << "Can't open the file: " << fileName << std::endl;
		return false;
	}

	dataOut << displayAllTransactions();
	dataOut.close();
	return true;
}

bool TransactionManager::saveFileWithDelimiter(const std::string fileName, const char delimiter)
{

	std::ofstream dataOut;
	dataOut.open(fileName, std::fstream::app);
	if (!dataOut)
	{
		std::cerr << "Can't open the file: " << fileName << std::endl;
		return false;
	}
	dataOut << displayAllTransactionsWithDelimiter(delimiter);
	dataOut.close();
	return true;
}

/***************************************************************************************
*	 General idea of this implementation from:
*    Title: CO3402 Object-Oriented Methods Assignment
*    Author: Mojtaba Hafezi
*    Date: 05/12/2016
*    Code version: 2.1
*	 Availablity: N.A. - UCLAN assignment
***************************************************************************************/
bool TransactionManager::loadFile(const std::string fileName, const char delimiter)
{
	//attributes required for the creation of the transaction objects
	std::string name;
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	double amount;
	std::string string1;
	std::string string2;
	std::string string3;
	std::string typeString;
	Debit::Authorisation authType;
	Creditpoint::Type creditType;
	Interest::Type  interestType;
	bool valid = false;
	std::ifstream file(fileName, std::ifstream::in);

	if (file) //if the file was found
	{
		//while there is something to read
		while (file)
		{
			std::string fileInput;
			getline(file, fileInput);	//Get the complete line into the string "fileInput"
			if (fileInput.size() <= 1)	//Skip over last empty line
			{
				continue;
			}

			//Pos points to the position of the delimiter
			size_t pos = 0;
			pos = fileInput.find(delimiter);	//find the position of the first occurence of delimiter
			std::string id = fileInput.substr(0, pos);	//Id is the substring from 0 to the position of the first delimiter
			fileInput.erase(0, pos + 1);	//erase it up to the delimiter (+1)
			//Ready to read in rest of data, requires to distinguish between Transactions
			int transactionType = getTransactionType(id);
			switch (transactionType)
			{
			case 1:
				name = "Debit";
				pos = fileInput.find(delimiter);
				day = std::stoi(fileInput.substr(0, pos));	//using the string to integer method
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				month = Date::getMonthByName(fileInput.substr(0, pos));	//using the helper method to get the month as int
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				year = std::stoi(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				//read time with specific delimiter
				pos = fileInput.find(delimiter);
				string1 = (fileInput.substr(0, pos));
				hour = stoi(string1.substr(0, 2));
				min = stoi(string1.substr(3, 2));
				sec = stoi(string1.substr(6, 2));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				amount = std::stod(fileInput.substr(0, pos));	//string to double method
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				string1 = (fileInput.substr(0, pos)); //card number
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				string2 = (fileInput.substr(0, pos)); //retailer name
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				string3 = (fileInput.substr(0, pos)); //location
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				typeString = fileInput.substr(0, pos);
				authType = Debit::getAuthorisationType(Debit::getAuthorisationTypeFromString(typeString)); //location
				addTransaction(new Debit(name, Date(year, month, day, hour, min, sec), amount, string1, string2, string3, authType));
				break;
			case 2:
				name = "Cashpoint";
				pos = fileInput.find(delimiter);
				day = std::stoi(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				month = Date::getMonthByName(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				year = std::stoi(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);

				pos = fileInput.find(delimiter);
				string1 = (fileInput.substr(0, pos));
				hour = stoi(string1.substr(0, 2));
				min = stoi(string1.substr(3, 2));
				sec = stoi(string1.substr(6, 2));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				amount = std::stod(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				string1 = (fileInput.substr(0, pos)); //locationid
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				string2 = (fileInput.substr(0, pos)); //card number
				addTransaction(new Cashpoint(name, Date(year, month, day, hour, min, sec), amount, string1, string2));
				break;
			case 3:
				name = "Direct Debit";
				pos = fileInput.find(delimiter);
				day = std::stoi(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				month = Date::getMonthByName(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				year = std::stoi(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);

				pos = fileInput.find(delimiter);
				string1 = (fileInput.substr(0, pos));
				hour = stoi(string1.substr(0, 2));
				min = stoi(string1.substr(3, 2));
				sec = stoi(string1.substr(6, 2));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				amount = std::stod(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				string1 = (fileInput.substr(0, pos)); //reference number
				addTransaction(new DirectDebit(name, Date(year, month, day, hour, min, sec), amount, string1));
				break;
			case 4:
				name = "Transfer";
				pos = fileInput.find(delimiter);
				day = std::stoi(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				month = Date::getMonthByName(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				year = std::stoi(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);

				pos = fileInput.find(delimiter);
				string1 = (fileInput.substr(0, pos));
				hour = stoi(string1.substr(0, 2));
				min = stoi(string1.substr(3, 2));
				sec = stoi(string1.substr(6, 2));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				amount = std::stod(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				string1 = (fileInput.substr(0, pos)); //acc nr
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				string2 = (fileInput.substr(0, pos)); //sort code
				fileInput.erase(0, pos + 1);
				addTransaction(new Transfer(name, Date(year, month, day, hour, min, sec), amount, string1, string2));
				break;
			case 5:
				name = "Creditpoint";
				pos = fileInput.find(delimiter);
				day = std::stoi(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				month = Date::getMonthByName(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				year = std::stoi(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);

				pos = fileInput.find(delimiter);
				string1 = (fileInput.substr(0, pos));
				hour = stoi(string1.substr(0, 2));
				min = stoi(string1.substr(3, 2));
				sec = stoi(string1.substr(6, 2));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				amount = std::stod(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				typeString = fileInput.substr(0, pos);
				creditType = Creditpoint::getCreditpointType(Creditpoint::getCreditpointTypeFromString(typeString)); //type
				addTransaction(new Creditpoint(name, Date(year, month, day, hour, min, sec), amount, creditType));
				break;
			case 6:
				name = "Debit";
				pos = fileInput.find(delimiter);
				day = std::stoi(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				month = Date::getMonthByName(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				year = std::stoi(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);

				pos = fileInput.find(delimiter);
				string1 = (fileInput.substr(0, pos));
				hour = stoi(string1.substr(0, 2));
				min = stoi(string1.substr(3, 2));
				sec = stoi(string1.substr(6, 2));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				amount = std::stod(fileInput.substr(0, pos));
				fileInput.erase(0, pos + 1);
				pos = fileInput.find(delimiter);
				typeString = fileInput.substr(0, pos); // interest type
				interestType = Interest::getInterestType(Interest::getInterestTypeFromString(typeString)); //location
				addTransaction(new Interest(name, Date(year, month, day, hour, min, sec), amount, interestType));
				break;
			default:
				break;
			}

		}
		file.close();
		valid = true;
	}
	else
	{
		//	throw SimpleException;
	}
	return valid;
}

bool TransactionManager::clearTransactions()
{
	linkedList.clear();
	return linkedList.header == 0;
}

TransactionManager::TransactionManager()
{

}
TransactionManager::~TransactionManager()
{
	clearTransactions();
}
