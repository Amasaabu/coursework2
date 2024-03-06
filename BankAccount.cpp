#include "BankAccount.h"
#include "fstream"


//CONSTRUCTORS
BankAccount::BankAccount() {
	this->accountBalance = 0;
}


void BankAccount::setBirthDate(int birthDate) {
	if (birthDate < 1 || birthDate>31) {
		throw invalid_argument("Invalid birth date entered, value must be between 1 and 31");
	}
	this->birthDate = birthDate;
}

int BankAccount::getBirthDate() {
	return this->birthDate;
}

void BankAccount::setBirthMonth(int birthMonth) {
	if (birthMonth < 1 || birthMonth>12) {
		throw invalid_argument("Invalid birth month entered, value must be between 1 and 12");
	}
	this->birthMonth = birthMonth;
}
int BankAccount::getBirthMonth() {
	return this->birthMonth;
}

void BankAccount::setBirthYear(int birthYear) {
	this->birthYear = birthYear;
}
int BankAccount::getBirthYear() {
	if (birthDate < 0001 || birthDate>9999) {
		throw invalid_argument("Invalid birth year entered, value must be between 1 and 31");
	}
	return this->birthYear;
}

string BankAccount::getAccountNumber()
{
	return this->accountNumber;
}

void BankAccount::setAccountNumber(string accountNumber)
{
	this->accountNumber = accountNumber;
}

void BankAccount::setEmail(string& email)
{
	this->email = email;
}
string BankAccount::getEmail()
{
	return  this->email;
}
void BankAccount::setPassword(string& password)
{
	this->password = password;
}
string BankAccount::getPasswprd()
{
	return  this->password;
}
void BankAccount::setPhoneNumber(string& phoneNumber)
{
	this->password = phoneNumber;
}
string BankAccount::getPhoneNumber()
{
	return this->phoneNumber;
}

void BankAccount::setFirstName(string& firstName)
{
	this->firstname = firstName;
}
string BankAccount::getFirstName()
{
	return this->firstname;
}

void BankAccount::setSurname(string& surname)
{
	this->surname = surname;
}
string BankAccount::getSurname()
{
	return this->surname;
}


void BankAccount::setAccountBalance(double& amount)
{
	this->accountBalance = amount;
}


double BankAccount::getAccountBalance()
{
	return this->accountBalance;
}

//transaction bankaccount::dodebitaccount(double amount) {
//	//ensure amount is not greater than available balance
//	double newamount = amount + this->accountbalance;
//	if (newamount < 0) throw runtime_error("account balance can not be negative");
//
//	//create transaction object
//	transaction txn;
//	txn.setamount(amount);
//	txn.settxnref();
//	txn.settxntype("debit");
//	txn.settxnref();
//
//	//push transaction object into 'transaction in ' account object
//
//	//change current account balance on bank account
//	this->accountbalance = accountbalance;
//	//return transaction
//}
