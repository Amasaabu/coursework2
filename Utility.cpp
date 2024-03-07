#include "Utility.h"
#include <iostream>

#include <fstream>
#include <string>
using namespace std;


//CONSTANT
const string fileExtension = ".txt";
string Utility::generateRandom(string prefix) {
	string random = to_string((rand() % 1000000000000));
	return (prefix + random);
}


void Utility::saveAccountToFilev1(BankAccount bankAccount) {
	ofstream file;
	file.open(to_string(bankAccount.getBirthDate()) + fileExtension);
	if (file.is_open()) {
		file.write((char*)&bankAccount, sizeof(bankAccount));
		file.close();
	}
	else {
		throw invalid_argument("Unable to create account");
	}
	cout << "Bank account created and Saved Successfully" << endl;
}
//void Utility::saveAccountToFile(BankAccount bankAccount) {
//	ofstream file;
//	file.open(bankAccount.getAccountNumber() + fileExtension);
//	if (file.is_open()) {
//		file.write((char*)&bankAccount, sizeof(bankAccount));
//		file.close();
//	}
//	else {
//		throw invalid_argument("Unable to create account");
//	}
//	cout << "Bank account created and Saved Successfully" << endl;
//}


BankAccount Utility::getAccountDetailsFromAccountNumber(string accountNumber) {
			BankAccount acct;
			ifstream readFIle;
			readFIle.open(accountNumber + fileExtension, ios::binary);
			if (readFIle.is_open()) {
				readFIle.read((char*)&acct, sizeof(acct));
				// readFIle.read((char*)&acct, sizeof(acct));
				readFIle.close();
			}
			else {
				throw runtime_error("Unable to get account details, ensure account number inputed is correct");
			} 
		return acct;
}

void Utility::verifyUserInput() {
	// check if there was an error reading the line or if there are any non-new line in the stream.
	if (cin.fail() || cin.peek() != '\n') {
		//clear error flag on the stream
		cin.clear();
		//clears the invalid input, size of input is max amount of stream and any new line in the stream.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw std::invalid_argument("****Invalid number passed***** \n Program Restarting....");
	}
}