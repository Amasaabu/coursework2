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
	string phoneNumber="";
	string surname="";
	string firstname="";
	double accountBalance=0;

	string accountType="SAVINGS";
public:
	BankAccount();
	string getAccountNumber();

	void setAccountNumber(string accountNumber);

	void setEmail(string& email);
	string getEmail();
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

	bool debitAccount(double);
	void creditAccount(double);

	void setAccountType(string);
	string getAccountType();

	friend istream& operator>>(istream& input, BankAccount& acct);
	friend ofstream& operator<<(ofstream& input, BankAccount& acct);

};


