// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



//to do
// start implementing transactions
// validate user input string fields to ensure numbers are not part of user input
// implement password validation
// store transaction history
// generate receipt for transaction
//store account in a directory

#include <iostream>
#include <fstream>
#include <string>
#include "BankAccount.h"
#include "Utility.h"
using namespace  std;

void registerAnAccountOperation();
void getAccountDetailsOperation();
void addCashOperation();
void withdrawCashOperation();


//initialize utilities globallu


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
		cout << "5. To exit the preogram" << endl;
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
				continue;
			}
			else if(firstInput == "3") {
				addCashOperation();
				continue;
			}
			else if (firstInput == "4") {
				withdrawCashOperation();
			}
			else if(firstInput=="5") {
				cout << "Safely exiting Program..."<<endl;
				return 0;
			}
			
			else {
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
}

//withdraw cash operation
void withdrawCashOperation() {
	string accountNumber = "";
	cout << "Please anter account Number below: " << endl;
	cin >> accountNumber;
	Utility::verifyUserInput();
	//get Account Details
	cout << "Searching for accouint..." << endl;
	BankAccount account = Utility::getAccountDetailsFromAccountNumber(accountNumber);
	cout << "Account Auth Succeeded!" << endl;
	cout << "Kindly enter amount you wish to WIthdraw: " << endl;
	double amount = 0;
	cin >> amount;
	Utility::verifyUserInput();
	bool isSuccessful = account.debitAccount(amount);
	isSuccessful = Utility::saveAccountToFile(account);
	if (!isSuccessful) {
		throw invalid_argument("Operation Failed");
		return;
	}
	cout << "*****Request Processed****" << endl;
	cout << "" << endl;
	cout << "Account Number: " << account.getAccountNumber() << endl;
	cout << "New Balance: " << account.getAccountBalance() << endl;
	cout << "" << endl;
	




}


//add cash details Operation
void addCashOperation() {
	string accountNumber = "";
	cout << "Please anter account Number below: " << endl;
	cin >> accountNumber;
	Utility::verifyUserInput();
	//get Account Details
	cout << "Searching for accouont..."<<endl;
	BankAccount account = Utility::getAccountDetailsFromAccountNumber(accountNumber);
	cout << "Account Auth Succeeded!" << endl;
	cout << "Kindly enter amount you wish to credit your account with below " << endl;
	double amount = 0;
	cin >> amount;
	Utility::verifyUserInput();
	account.creditAccount(amount);
	bool isOperationSuccessful = Utility::saveAccountToFile(account);
	if (!isOperationSuccessful) {
		throw invalid_argument("Operation failed while Updating details!");
		return;
	}
	cout << "*******Cash added*********" << endl;
	cout << "Account Number: " << account.getAccountNumber() << endl;
	cout << "New Balance: " << account.getAccountBalance() << endl;
	cout << "****************" << endl;
}


//Get account details operation
void getAccountDetailsOperation() {
	string accountNumber="";
	cout << "Input Account Number Below: " << endl;
	cin >> accountNumber;
	BankAccount accountDetails = Utility::getAccountDetailsFromAccountNumber(accountNumber);
	cout << "*******************" << endl;
	cout << "Searching for Account Details..." << endl;
	cout << "Account Details: " << endl;
	cout << "" << endl;
	cout << "Account Number: " << accountDetails.getAccountNumber() << endl;
	cout << ".........................." << endl;
	cout << "Surname: " << accountDetails.getSurname() << endl;
	cout << ".........................." << endl;
	cout << "FirsName: " << accountDetails.getFirstName() << endl;
	cout << ".........................." << endl;
	cout << "Email: " << accountDetails.getEmail() << endl;
	cout << ".........................." << endl;
	cout << "Date of birth: " << accountDetails.getBirthDate() << "/"<<accountDetails.getBirthMonth()<<"/"<<accountDetails.getBirthYear()<< endl;
	cout << ".........................." << endl;
	cout << "Account Balance: " << accountDetails.getAccountBalance() << endl;
	cout << "" << endl;

	return;


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
	Utility::verifyUserInput();
	bankAccount.setBirthYear(birthYear);

	cout << "Please input your birth month (e.g 12 for December): " << endl;
	cin >> birthMonth;
	Utility::verifyUserInput();
	bankAccount.setBirthMonth(birthMonth);

	cout << "Please input your birth date: " << endl;
	cin >> birthDate;
	Utility::verifyUserInput();
	bankAccount.setBirthDate(birthDate);

	cout << "Please input your phone number" << endl;
	cin >> phoneNumber;
	bankAccount.setPhoneNumber(phoneNumber);

	//generate account number
	string accountNumber = Utility::generateRandom("ACC-");
	bankAccount.setAccountNumber(accountNumber);
	bool isOperationSuccessful = Utility::saveAccountToFile(bankAccount);
	if (!isOperationSuccessful) {
		throw invalid_argument("Unable to create account");
		return;
	}
	//Display bank account details to customer
	cout << "****Account Details***" << endl;
	cout << "1. Account Number: " << bankAccount.getAccountNumber() << endl;
	cout << "1. Surname: " << bankAccount.getSurname() << endl;
	cout << "****************" << endl;
}








