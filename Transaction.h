#pragma once
#include <iostream>


using namespace std; 
class Transaction {

private:
	double amount;
	string dateTIme;
	string txnRef;
	string txnType;

public:
	double getAmount();

	void setAmount(double);

	string getDateTIme();

	void setDateTIme(int dateTIme);

	//void getSourceAccount();

	//void setSourceAccount(int sourceAccount);

	//void getDestAccount();

	//void setDestAccount(int destAccount);

	string getTxnRef();

	void setTxnRef(string);

	string getTxnType();

	void setTxnType(string);
};

