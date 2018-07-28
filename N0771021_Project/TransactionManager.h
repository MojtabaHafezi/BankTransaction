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
	bool addTransaction(Transaction* pTransaction);
	bool removeTransaction();
	const std::string displayAllTransactions();
	const std::string displayAllTransactionsWithDelimiter(const char delimiter);

	const int getSize();
	const int getTransactionType(std::string identifier);
	void simpleSort();
	const std::string linearSearch(time_t pTime);
	const std::string linearSearchAll(time_t pTime);
	const std::string binarySearch(time_t pTime);

	bool saveFile(const std::string fileName);
	bool saveFileWithDelimiter(const std::string fileName, const char delimiter);
	bool loadFile(const std::string fileName, const char delimiter);
	bool clearTransactions();
	TransactionManager();

	~TransactionManager();
};

