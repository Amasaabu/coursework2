#include "Utility.h"
#include <iostream>
#include "BankAccount.h"
#include <fstream>
#include <string>

#include "vector";
using namespace std;


//CONSTANT
const string fileExtension = ".bin";
const string bankFile = "bank.txt";
string Utility::generateRandom(string prefix) {
	string random = to_string((rand() % 1000000000000));
	return (prefix + random);
}

bool Utility::saveAccountToFile(BankAccount bankAccount) {
	ofstream file;
	file.open(bankAccount.getAccountNumber() + fileExtension);
	if (file.is_open()) {
		//file.write((char*)&bankAccount, sizeof(bankAccount));
		bankAccount.serialize(file);
		file.close();
		return true;
	}
	else {
		return false;
	}
}


BankAccount Utility::getAccountDetailsFromAccountNumber(string accountNumber) {
	BankAccount account;
	ifstream readFIle;
	readFIle.open(accountNumber + fileExtension);
	if (readFIle.is_open()) {
		//readFIle.read((char*)&account, sizeof(account));
		account.deserialize(readFIle);
		readFIle.close();
	}
	else {
		throw invalid_argument("Unable to get account details, ensure account number inputed is correct");
	}
	return account;
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

bool Utility::saveBankToArray(BankAccount acct) {
	bool result = false;
	ofstream file;
	file.open(bankFile, ios::app);
	if (file.is_open()) {
		file << acct.getAccountNumber() << " " << acct.getEmail() << " " << " "
			<< acct.getPhoneNumber() << " " << acct.getSurname() << " " << acct.getFirstName() << " "
			<< acct.getAccountBalance() << " " << acct.getBirthDate() << " " << acct.getBirthMonth() << " "
			<< acct.getBirthYear() << endl;
		file.close();
		return true;
	}

	return result;
}


BankAccount Utility::getBankDetailsFromFile(string acctNumber) {
	ifstream file;
	file.open(bankFile);
	BankAccount temp;
	if (file.is_open()) {
		while (file>>temp) {
			//check each item from the text file
			if (acctNumber == temp.getAccountNumber()) {
				break;
			}
		}
	}
	return temp;
}