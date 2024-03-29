#include "Utility.h"
#include <iostream>
#include "BankAccount.h"
#include <fstream>
#include <string>

#include "vector";
using namespace std;


//CONSTANT
const double interestRateForSavingsAccount = 0.1; //10 percent
const double interestRateForCurrent = 0.05; //5 percent
const string bankFile = "bank.txt";


//Utility static method to generate random account number
string Utility::generateRandom(string& prefix) {
	string random="";
	for (int i = 0; i <= 6; i++) {
		 random = random+ to_string((rand() % 9));
	}
	return (prefix + random);
}


//Utility static method to verify user input
void Utility::verifyUserInput() {
	// check if there was an error reading the line or if there are any non-new line in the stream.
	if (cin.fail() || cin.peek() != '\n') {
		//clear error flag on the stream
		cin.clear();
		//clears the invalid input, size of input is max amount of stream and any new line in the stream.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw std::invalid_argument("****Invalid input detected****");
	}
}
/**
* This saves a bank account to the file
*/
bool Utility::saveBankToFile(BankAccount& acct) {
	bool result = false;
	ofstream file;
	file.open(bankFile, ios::app);
	if (file.is_open()) {
		file << acct <<endl;
		file.close();
		return true;
	}

	return result;
}

/**
* Searches the bank.txt file for account number and returns details
*/
BankAccount Utility::getBankDetailsFromFile(string& acctNumber) {
	ifstream file;
	file.open(bankFile);
	BankAccount temp;
	BankAccount foundBankAccount;
	if (file.is_open()) {
		while (file>>temp) {
			//check each item from the text file
			if (acctNumber == temp.getAccountNumber()) {
				foundBankAccount = temp;
				break;
			}
		}
		file.close();
	}
	else {
		throw exception("No account found, kindly try again, or create a new account");
	}
	//checking if no account was found
	if (foundBankAccount.getAccountNumber() == "") {
		throw exception("No account found, kindly try again, or create a new account");
	}
	return foundBankAccount;
}

/**
* Update a singe bank account in file
*/
void Utility::updateAccountInFile(BankAccount& updatedAcct) {
	//account already available, we now try to update in file
	string tempFile = "update.txt";
	ifstream inFile;
	ofstream outfile;
	inFile.open(bankFile);
	outfile.open(tempFile);
	BankAccount temp;
	if (!inFile.is_open()) {
		//IO exception
		throw invalid_argument("Unable to open file");
	}
	while (inFile>>temp)
		{
		if (temp.getAccountNumber() == updatedAcct.getAccountNumber()) {
				//this is where we update the file
				outfile << updatedAcct;
		}
		else {
			outfile << temp;
		}
		}
	inFile.close();
	outfile.close();

	const char tempFileChar[] = "update.txt";
	const char bankFileChar[] = "bank.txt";
	int result = remove(bankFileChar);
	int result2=rename(tempFileChar, bankFileChar);
	if (result != 0 && result2 != 0) {
		throw invalid_argument("Unable to update amount");
	}
	return;
}

/**
* Add interest to all account, savings and current account rate are static
* Method checks each account on file to see account type and adds interest appropriately
* All account has an account type. As the class initializes the default account type to SAVINGS
*/
void Utility::addInterestToAllAccount()
{
	cout << "NOTE: " << endl;
	cout << "Saving Interest Rate: " << interestRateForSavingsAccount << endl;
	cout << "Current Interest Rate: " << interestRateForCurrent << endl;
	string tempFileName = "update.txt";
	//load all account
	ifstream file;
	ofstream outFile;
	file.open(bankFile);
	outFile.open(tempFileName);
	BankAccount temp;

	if (!file.is_open() || !outFile.is_open()) {
		throw invalid_argument("Account could not be opened");
	}

		while (file >> temp) {
			if (temp.getAccountType() == "SAVINGS") {
				//interest rate for savings
				double interestAmt = interestRateForSavingsAccount * temp.getAccountBalance();
				double newAmount = interestAmt + temp.getAccountBalance();
				temp.setAccountBalance(newAmount);
				
			}
			else if (temp.getAccountType() == "CURRENT") {
				//interest rate for current
				double interestAmt = interestRateForCurrent * temp.getAccountBalance();
				double newAmount = interestAmt + temp.getAccountBalance();
				temp.setAccountBalance(newAmount);
			}

			outFile<<temp;			
		}
		outFile.close();
		file.close();
	const char tempFileChar[] = "update.txt";
	const char bankFileChar[] = "bank.txt";
	int result = remove(bankFileChar);
	int result2 = rename(tempFileChar, bankFileChar);
	if (result != 0 && result2 != 0) {
		throw invalid_argument("Unable to update");
	}
	cout << "***Operation completed without errors****" << endl;;
	return;
}

/*
* Get All Account and return a vector
* Since we can not tell the total amount of account we are going to have on file
*/
vector<BankAccount> Utility::getAllAccount() {
	ifstream file;
	file.open(bankFile);
	BankAccount temp;
	vector<BankAccount> foundBankAccounts;
	if (file.is_open()) {
		while (file >> temp) {
			//check each item from the text file
			foundBankAccounts.push_back(temp);
		}
		file.close();
	}
	else {
		throw exception("Unable to access bank file");
	}
	return foundBankAccounts;
}