#include "BankAccount.h"
#include "fstream"


//CONSTRUCTORS
BankAccount::BankAccount() {
	this-> birthMonth = 0;
	this-> birthDate = 0;
	this-> birthYear = 0;

	this-> accountNumber="";
	this-> email="";
	this-> phoneNumber="";
	this-> surname="";
	this-> firstname="";
	this-> password="";
	this-> accountBalance = 0;

	this-> accountType="SAVINGS";

}

void BankAccount::setPassword(string& password) {
	this->password = password;
}

string BankAccount::getPassword() {
	return this->password;
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
	if (birthYear < 1000 || birthYear>9999) {
		throw invalid_argument("Invalid birth year entered");
	}
	this->birthYear = birthYear;
}
int BankAccount::getBirthYear() {
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
void BankAccount::setPhoneNumber(string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
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

bool BankAccount::debitAccount(double amount) {
	bool result = false;
	double temporaryNewBalance = this->accountBalance - amount;
	if (temporaryNewBalance < 0)
	{
		cout<< "*****Insufficient account balance to complete request*****"<<endl;
		return false;
	}
	this->accountBalance = temporaryNewBalance;
	result = true;
	return result;
}


void BankAccount::creditAccount(double amount) {
	double newBalance = this->accountBalance + amount;
	this->accountBalance = newBalance;
}

void BankAccount::setAccountType(string acctType)
{
	if (acctType == "SAVINGS" || acctType == "CURRENT") {
		this->accountType = acctType;
		return;
	}
	throw invalid_argument("Account Type Entered not recognized");
}

string BankAccount::getAccountType()
{
	return this->accountType;
}

istream& operator>>(istream& input, BankAccount& acct) {
	input >> acct.accountNumber >> acct.email >> acct.phoneNumber
		>> acct.surname >> acct.firstname >> acct.accountBalance >> acct.birthMonth
		>> acct.birthDate >> acct.birthYear>>acct.accountType>>acct.password;
	return input;
}

ofstream& operator<<(ofstream& output, BankAccount& acct) {
	output << acct.accountNumber << " " << acct.email << " "
		<< acct.phoneNumber << " " << acct.surname << " " << acct.firstname << " "
		<< acct.accountBalance << " " << acct.birthDate << " " << acct.birthMonth << " "
		<< acct.birthYear << " " << acct.accountType <<" " << acct.password << endl;;
	return output;
}

