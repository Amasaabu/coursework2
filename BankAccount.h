#pragma once
#include <iostream>
#include "Transaction.h"

using namespace std;
class BankAccount
{
private:
	int birthMonth;
	int birthDate;
	int birthYear;

	string accountNumber;
	string email;
	string password;
	string phoneNumber;
	string surname;
	string firstname;
	double accountBalance;
	Transaction transaction[];
public:
	BankAccount();
	string getAccountNumber();

	void setAccountNumber(string accountNumber);

	void setEmail(string& email);
	string getEmail();
	void setPassword(string& password);
	string getPasswprd();
	void setPhoneNumber(string& phoneNumber);
	string getPhoneNumber();

	void setFirstName(string& firstName);
	string getFirstName();
	void setSurname(string&);
	string getSurname();

	
	double getAccountBalance();
	void setAccountBalance(double&);

	void setBirthDate(int);
	int getBirthDate();

	void setBirthMonth(int);
	int getBirthMonth();

	void setBirthYear(int);
	int getBirthYear();


	Transaction doDebitAccount(double);
	int doCreditAccount(double);

};

