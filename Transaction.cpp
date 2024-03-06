#include "Transaction.h"



double  Transaction::getAmount() {
return this->amount;
}

void Transaction::setAmount(double amount){
	this->amount = amount;
}

string Transaction::getDateTIme(){
	return this->getDateTIme();
}

void Transaction::setDateTIme(int dateTIme) {
	this->dateTIme = dateTIme;
}

string Transaction::getTxnRef() {
	return this->txnRef;
}

void Transaction::setTxnRef(string txnRef) {
	this->txnRef = txnRef;
}

string Transaction::getTxnType(){
	return this->txnType = txnType;
}

void Transaction::setTxnType(string xnType){
	this->txnType = txnType;
}
