#include "Operations.h"


#include <iostream>
#include <string>
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
		cout << "******Operation aborted!!!" << endl;
		return;
	}
}

/**
*Withdraw Cash from an account
* Request User to input account number and then validate this account
* Request user to input amount to withdraw
* Account can not go into negative
*/
void Operations::withdrawCashOperation(BankAccount& account) {
	cout << "Kindly enter amount to withdraw below: " << endl;
	double amount = 0;
	cin >> amount;
	Utility::verifyUserInput();
	bool isSuccessful = account.debitAccount(amount);
	if (!isSuccessful) {
		//operation failed for some other reason apart from insufficient balance
		cout<< "Operation Failed"<<endl;
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
void Operations::addCashOperation(BankAccount& account) {
	cout << "Kindly enter amount to add to account below: "<<endl;
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
void Operations::getAccountDetailsOperation(BankAccount& accountDetails) {
	cout << "*******************" << endl;
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
* Authenticate Bank account via surname and return bank account object
*/
BankAccount Operations::authenticateBankAccount() {
	string accountNumber = "";
	cout << "Input Account Number Below: " << endl;
	cin >> accountNumber;
	BankAccount accountDetails = Utility::getBankDetailsFromFile(accountNumber);
	cout << "*******************" << endl;
	cout << "To authenticate, input account surname below" << endl;
	string inputedSurname = "";
	cin >> inputedSurname;
	Utility::verifyUserInput();
	if (inputedSurname != accountDetails.getSurname()) {
		throw exception("Unable to authenticate account");
	}
	cout << "*****Authentication Suceeded****"<<endl;
	return accountDetails;
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
	Utility::verifyUserInput();
	bankAccount.setFirstName(firstname);

	cout << "Please input your lastName/surname/familyname: " << endl;
	cin >> surname;
	Utility::verifyUserInput();
	bankAccount.setSurname(surname);

	cout << "Please input your email: " << endl;
	cin >> email;
	Utility::verifyUserInput();
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

	cout << "Please input your phone number, No country code" << endl;
	cin >> phoneNumber;
	bool isInvalid = Utility::checkInvalidNumInString(phoneNumber);
	if (isInvalid) throw invalid_argument("Ensure phonenumber are all digit");
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

/**
* Update account details
*/

void Operations::updateAccountDetailsOperation() {
	cout << "Kindly enter account number you wish to update details" << endl;
	cout << "***Note: You can only modify firstname, email, phone number and account type" << endl;
	string accountNumber;
	cin >> accountNumber;
	Utility::verifyUserInput();
	
	//get account from account number
	BankAccount userAccount= Utility::getBankDetailsFromFile(accountNumber);
	cout << "Account found, welcome: " << userAccount.getSurname() << endl;;

	string newFistName;
	//clear any character in the buffer before calling getline()
	cin.clear();
	cin.ignore();
	cout << "Enter new first name you wish to make use of below or otherwise leave blank if you want it to remain as " << userAccount.getFirstName() << endl;
	getline(cin,newFistName);
	if (newFistName == "") newFistName = userAccount.getFirstName();
	userAccount.setFirstName(newFistName);

	string newEmail;
	cout << "Enter new email address you wish to make use of below or otherwise leave blank if you want it to remain as " << userAccount.getEmail() << endl;
	getline(cin, newEmail);
	if (newEmail == "") newEmail = userAccount.getEmail();
	userAccount.setEmail(newEmail);

	string phoneNumber;
	cout << "Enter new phone number you wish to make use of below or otherwise leave blank if you want it to remain as " << userAccount.getEmail() << endl;
	getline(cin, phoneNumber);
	if (phoneNumber == "") phoneNumber = userAccount.getPhoneNumber();
	userAccount.setPhoneNumber(phoneNumber);

	//Update
	Utility::updateAccountInFile(userAccount);
	cout << "Account updated successfully" << endl;
}