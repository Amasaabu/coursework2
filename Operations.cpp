#include "Operations.h"


#include <iostream>
#include "Utility.h"

using namespace std;
/**This function handles adding interest to an account*/
void Operations::addInterestToAllAccountsOperation() {
	int confirmation = 0;
	cout << "Are you sure you want to add interest to all account? Enter (1) if yes" << endl;;
	cin >> confirmation;
	Utility::verifyUserInput();
	if (confirmation == 1) {
		Utility::addInterestToAllAccount();
		return;
	}
	else {
		cout << "******Operation aborted!!! exiting to main menu******" << endl;
		return;
	}
}

/**
*Withdraw Cash from an account
* Request User to input account number and then validate this account
* Request user to input amount to withdraw
* Account can not go into negative
*/
void Operations::withdrawCashOperation() {
	string accountNumber = "";
	cout << "Please anter account Number below: " << endl;
	cin >> accountNumber;
	Utility::verifyUserInput();
	//get Account Details
	cout << "Searching for account..." << endl;
	BankAccount account = Utility::getBankDetailsFromFile(accountNumber);
	cout << "Account Auth Succeeded!!" << endl;
	cout << "Kindly enter amount you wish to WIthdraw: " << endl;
	double amount = 0;
	cin >> amount;
	Utility::verifyUserInput();
	bool isSuccessful = account.debitAccount(amount);
	if (!isSuccessful) {
		throw invalid_argument("Operation Failed");
		return;
	}
	Utility::updateAccountInFile(account);
	cout << "*****Request Processed****" << endl;
	cout << "" << endl;
	cout << "Account Number: " << account.getAccountNumber() << endl;
	cout << "New Balance: " << account.getAccountBalance() << endl;
	cout << "*********" << endl;
}


/**
* Add cash operation
* Request User to input account number and then validate this account
* Request user to input amount to add
*/
void Operations::addCashOperation() {
	string accountNumber = "";
	cout << "Please anter account Number below: " << endl;
	cin >> accountNumber;
	Utility::verifyUserInput();
	//get Account Details
	cout << "Searching for accouont..." << endl;
	BankAccount account = Utility::getBankDetailsFromFile(accountNumber);
	cout << "Account Auth Succeeded!" << endl;
	cout << "Kindly enter amount you wish to credit your account with below " << endl;
	double amount = 0;
	cin >> amount;
	Utility::verifyUserInput();
	account.creditAccount(amount);
	Utility::updateAccountInFile(account);
	cout << "*******Cash added*********" << endl;
	cout << "Account Number: " << account.getAccountNumber() << endl;
	cout << "New Balance: " << account.getAccountBalance() << endl;
	cout << "****************" << endl;
}


/**
* Get account details operation
* Request User to input account number and then validate this account
*/
void Operations::getAccountDetailsOperation() {
	string accountNumber = "";
	cout << "Input Account Number Below: " << endl;
	cin >> accountNumber;
	BankAccount accountDetails = Utility::getBankDetailsFromFile(accountNumber);
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
	cout << "Account Type: " << accountDetails.getAccountType() << endl;
	cout << ".........................." << endl;
	cout << "Date of birth: " << accountDetails.getBirthDate() << "/" << accountDetails.getBirthMonth() << "/" << accountDetails.getBirthYear() << endl;
	cout << ".........................." << endl;
	cout << "Account Balance: " << accountDetails.getAccountBalance() << endl;
	cout << "" << endl;

	return;


}

/**
* Operation to open a new account
*/
void Operations::registerAnAccountOperation() {
	string email = "";
	string password = "";
	string phoneNumber = "";
	string surname = "";
	string firstname = "";
	int accountType = 1;
	int birthYear = 0;
	int birthMonth = 0;
	int birthDate = 0;


	BankAccount bankAccount;
	cout << "Kindly provide the details required below: " << endl;
	cout << "Please input your firstname: " << endl;
	cin >> firstname;
	bankAccount.setFirstName(firstname);

	cout << "Please input your lastName/surname/familyname: " << endl;
	cin >> surname;
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

	cout << "Please select account type, (1) for savings (2) for current. If invalid type is entered account is assumed to be savings" << endl;
	cin >> accountType;
	Utility::verifyUserInput();
	if (accountType == 2) {
		bankAccount.setAccountType("CURRENT");
	}

	//generate account number
	string accountNumber = Utility::generateRandom("ACC-");
	bankAccount.setAccountNumber(accountNumber);
	bool isOperationSuccessful = Utility::saveBankToFile(bankAccount);
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