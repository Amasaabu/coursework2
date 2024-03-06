// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



//to do
// validate date of bith
// implement password validation
// store transaction history
// generate receipt for transaction
//store account in a directory

#include <iostream>
#include <fstream>
#include <string>
#include "BankAccount.h"
using namespace  std;

void registerAnAccountOperation();
void getAccountDetailsOperation();

void saveAccountToFile(BankAccount);
BankAccount getAccountDetailsFromAccountNumber(string accountNumber);
string generateRandom(string);

//CONSTANT
const string fileExtension = ".bin";
int main()
{
	srand((unsigned)time(NULL));

	bool isValidInput = true;
	string firstInput = "";
	do {
		cout << "Welcome to our Banking app" << endl;
		cout << "Kindly enter an option from the list below" << endl;
		cout << "1. Register a new account" << endl;
		cout << "2. View Account Details" << endl;
		cout << "3. Deposit Cash" << endl;
		cout << "4. Withdraw Cash" << endl;
		cin >> firstInput;
		cout << "*****************" << endl;
		try
		{
			if (firstInput == "1") {
				registerAnAccountOperation();
				continue;

			}
			else if (firstInput == "2") {
				getAccountDetailsOperation();
			}
			else if(firstInput == "3") {

			} else {
				cout << "An invalid input entered, please try again " << endl;
				continue;
			}
		}
		catch (invalid_argument& e) {
			cerr << e.what() << endl;
			cout << "Exiting program..." << endl;
		}

		catch (const std::exception&)
		{
			cout << "An exception occured"<<endl;
		}

	} while (isValidInput);




	
	//BankAccount account2 = BankAccount();
	//double amt = 300;
	//string email = "ade@ade.com";
	//account2.setAccountBalance(amt);
	//account2.setAccountNumber("342313");
	//account2.setEmail(email);
	//saveAccountToFile(account2);

}

//Get account details operation
void getAccountDetailsOperation() {
	string accountNumber="";
	cout << "Input Account Number Below: " << endl;
	cin >> accountNumber;
	BankAccount accountDetails = getAccountDetailsFromAccountNumber(accountNumber);
	cout << "*******************" << endl;
	cout << "Searching for Account Details..." << endl;
	cout << "See Account Details Below" << endl;
	cout << "********** * ********" << endl;
	cout << "Account Number: " << accountDetails.getAccountNumber() << endl;
	cout << "Surname: " << accountDetails.getSurname() << endl;
	cout << "FirsName: " << accountDetails.getFirstName() << endl;
	cout << "Email: " << accountDetails.getEmail() << endl;
	cout << "Date of birth: " << accountDetails.getBirthDate() << "/"<<accountDetails.getBirthMonth()<<"/"<<accountDetails.getBirthYear()<< endl;
	cout << "Account Balance: " << accountDetails.getAccountBalance() << endl;
	cout << "********** * ********" << endl;


}

//Operation to create a new account
void registerAnAccountOperation(){
	string email="";
	string password="";
	string phoneNumber="";
	string surname="";
	string firstname="";
	int birthYear=0;
	int birthMonth=0;
	int birthDate=0;


	BankAccount bankAccount;
	cout << "Kindly provide the details required below: " << endl;
	cout << "Please input your firstname: " << endl;
	cin >> firstname;
	bankAccount.setFirstName(firstname);

	cout << "Please input your lastName/surname/familyname: " << endl;
	cin >>surname;
	bankAccount.setSurname(surname);

	cout << "Please input your email: " << endl;
	cin >> email;
	bankAccount.setEmail(email);

	cout << "Please input your birth year (e.g 2002): " << endl;
	cin >> birthYear;
	bankAccount.setBirthYear(birthYear);

	cout << "Please input your birth month (e.g 12 for December): " << endl;
	cin >> birthMonth;
	bankAccount.setBirthMonth(birthMonth);

	cout << "Please input your birth date: " << endl;
	cin >> birthDate;
	bankAccount.setBirthDate(birthDate);

	cout << "Please input your phone number" << endl;
	cin >> phoneNumber;
	bankAccount.setPhoneNumber(phoneNumber);

	//generate account number
	string accountNumber = generateRandom("ACC-");
	bankAccount.setAccountNumber(accountNumber);
	saveAccountToFile(bankAccount);

	//Display bank account details to customer
	cout << "****Account Details***" << endl;
	cout << "1. Account Number: " << bankAccount.getAccountNumber() << endl;
	cout << "1. Surname: " << bankAccount.getSurname() << endl;
	cout << "****************" << endl;
}


void saveAccountToFile(BankAccount bankAccount) {
	ofstream file;
	file.open(bankAccount.getAccountNumber()+ fileExtension);
	if (file.is_open()) {
		file.write((char*)&bankAccount, sizeof(bankAccount));
		file.close();
	}
	else {
		throw invalid_argument("Unable to create account");
	}
	cout << "Bank account created and Saved Successfully"<<endl;
}

BankAccount getAccountDetailsFromAccountNumber(string accountNumber) {
	BankAccount account;
	ifstream readFIle;
	readFIle.open(accountNumber+fileExtension);
	if (readFIle.is_open()) {
		readFIle.read((char*)&account, sizeof(account));
		readFIle.close();
	}
	else {
		throw invalid_argument("Unable to get account details, ensure account number inputed is correct");
	}
	return account;
}


string generateRandom(string prefix) {

	string random = to_string((rand()%1000000000000));
	return (prefix + random);
}