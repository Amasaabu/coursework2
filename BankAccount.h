#pragma once
#include <iostream>

using namespace std;
class BankAccount
{
private:
	int birthMonth=0;
	int birthDate=0;
	int birthYear=0;

	string accountNumber="";
	string email="";
	string currency="";
	string surname="";
	string firstname="";
	string password="";
	double accountBalance=0;

	string accountType="SAVINGS";
public:
	BankAccount();
	string getAccountNumber();
	void setAccountNumber(string& accountNumber);

	void setEmail(string& email);
	string getEmail();

	void setCurrenecy(string& currency);
	string getCurrency();

	void setFirstName(string& firstName);
	string getFirstName();

	void setPassword(string& password);
	string getPassword();

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

	bool debitAccount(double);
	void creditAccount(double);

	void setAccountType(string);
	string getAccountType();

	//overide the >> and << operator so we can serialize and deserialize objects of class BankAccount easily
	friend istream& operator>>(istream& input, BankAccount& acct);
	friend ofstream& operator<<(ofstream& input, BankAccount& acct);

};


