#include "Utility.h"
#include <iostream>
#include "BankAccount.h"
#include <fstream>
#include <string>

#include "vector";
using namespace std;


//CONSTANT
const double interestRateForSavingsAccount = 0.2;
const double interestRateForCurrent = 0.05;
const string bankFile = "bank.txt";
string Utility::generateRandom(string prefix) {
	string random = to_string((rand() % 1000000000000));
	return (prefix + random);
}



void Utility::verifyUserInput() {
	// check if there was an error reading the line or if there are any non-new line in the stream.
	if (cin.fail() || cin.peek() != '\n') {
		//clear error flag on the stream
		cin.clear();
		//clears the invalid input, size of input is max amount of stream and any new line in the stream.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw std::invalid_argument("****Invalid input detected***** \nProgram Restarting....");
	}
}

bool Utility::saveBankToFile(BankAccount acct) {
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


BankAccount Utility::getBankDetailsFromFile(string acctNumber) {
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
	}
	//checking if no account was found
	if (foundBankAccount.getAccountNumber() == "") {
		throw invalid_argument("No account found, kindly try again, or create a new account");
	}
	return foundBankAccount;
}


bool Utility::updateAccountInFile(BankAccount updatedAcct) {
	//account already available, we now try to update in file
	string tempFile = "update.txt";
	ifstream inFile;
	ofstream outfile;
	inFile.open(bankFile);
	outfile.open(tempFile);
	BankAccount temp;
	bool resultOfOperation = false;
	if (!inFile.is_open()) {
		//IO exception
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
			resultOfOperation = true;
		}
	const char* tempFileChar = tempFile.c_str();
	const char* bankFileChar = bankFile.c_str();
	remove(bankFileChar);
	rename(tempFileChar, bankFileChar);
	return resultOfOperation;
}


void Utility::addInterestToAllAccount()
{
	string tempFileName = "temp.txt";
	//load all account
	ifstream file;
	ofstream outFile;
	file.open(bankFile);
	outFile.open(tempFileName);
	BankAccount temp;

	if (file.is_open()&&outFile.is_open()) {
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
			const char* tempChar = tempFileName.c_str();
			const char* newNameChar = bankFile.c_str();
			rename(tempChar, newNameChar);
			
		}
	} 
}