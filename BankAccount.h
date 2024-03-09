#pragma once
#include <iostream>
#include "Transaction.h"

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
//	Transaction transaction[];
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


	void serialize(std::ostream& os) const {
		// Serialize each member variable individually
		os << accountNumber << " " << email << " "  << " "
			<< phoneNumber << " " << surname << " " << firstname << " "
			<< accountBalance << " " << birthMonth << " " << birthDate << " "
			<< birthYear << "\n";
	}

	void deserialize(std::istream& is) {
		// Deserialize each member variable individually
		is >> accountNumber >> email  >> phoneNumber
			>> surname >> firstname >> accountBalance >> birthMonth
			>> birthDate >> birthYear;
	}

};

