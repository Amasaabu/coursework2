#include "Operations.h"


#include <iostream>
#include <string>
#include "Utility.h"

using namespace std;
/**
*This function handles adding interest to an account
* This operation is to be completed by an admin
*/
void Operations::addInterestToAllAccountsOperation() {
	int confirmation = 0;
	cout << "Are you sure you want to add interest to all account? Enter (1) if yes" << endl;
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
* Operation can only be completed by a validated user
* Request user to input amount to withdraw
* Account can not go into negative
* Method would not allow negative amount
*/
void Operations::withdrawCashOperation(BankAccount& account) {
	cout << "Kindly enter amount to withdraw below: " << endl;
	double amount = 0;
	cin >> amount;
	if (amount < 0) {
		cout << "Error: Amount to be withdrawn can not be less than 0" << endl;
		return;
	}
	if (cin.fail() || cin.peek() != '\n') {
		//clear error flag on the stream
		cin.clear();
		//clears the invalid input, size of input is max amount of stream and any new line in the stream.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << ("****Invalid input detected****") << endl;
		return;
	}
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
* Only positive numbers would be accepted
*/
void Operations::addCashOperation(BankAccount& account) {
	cout << "Kindly enter amount to add to account below: "<<endl;
	double amount = 0;
	cin >> amount;
	if (amount < 0) {
		cout << "Error: Amount to be added can not be less than 0"<<endl;
		return;
	}
	if (cin.fail() || cin.peek() != '\n') {
		//clear error flag on the stream
		cin.clear();
		//clears the invalid input, size of input is max amount of stream and any new line in the stream.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << ("****Invalid input detected****") << endl;
		return;
	}
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
	cout << "Account Currency: " << accountDetails.getCurrency() << endl;
	cout << ".........................." << endl;
	cout << "Date of birth: " << accountDetails.getBirthDate() << "/" << accountDetails.getBirthMonth() << "/" << accountDetails.getBirthYear() << endl;
	cout << ".........................." << endl;
	cout << "Account Balance: " << accountDetails.getAccountBalance() << endl;
	cout << "" << endl;
	return;
}

/**
* Authenticate Bank account via account number and password created and return bank account object
*/
BankAccount Operations::authenticateBankAccount() {
	string accountNumber = "";
	cout << "Input Account Number Below: " << endl;
	cin >> accountNumber;
	BankAccount accountDetails = Utility::getBankDetailsFromFile(accountNumber);
	cout << "*******************" << endl;
	cout << "To authenticate, input account password below(CASE SENSITIVE). If you have forgotten your password kindly reach out to an admin to reset for you" << endl;
	string password = "";
	cin >> password;
	Utility::verifyUserInput();
	if (password != accountDetails.getPassword()) {
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

	cout << "Please create an account password you would like to use to authenticate: " << endl;
	cin >> password;
	Utility::verifyUserInput();
	bankAccount.setPassword(password);

	cout << "Please input your birth year (e.g 2002): " << endl;
	cin >> birthYear;
	Utility::verifyUserInput();
	bankAccount.setBirthYear(birthYear);

	cout << "Please input your birth month (e.g 12 for December): " << endl;
	cin >> birthMonth;
	Utility::verifyUserInput();
	bankAccount.setBirthMonth(birthMonth);

	cout << "Please input your birth date (a value between 1-31): " << endl;
	cin >> birthDate;
	Utility::verifyUserInput();
	bankAccount.setBirthDate(birthDate);


	cout << "Please select account type, (1) for savings (2) for current" << endl;
	cin >> accountType;
	Utility::verifyUserInput();
	if (accountType == 2) {
		bankAccount.setAccountType("CURRENT");
	}
	else if (accountType == 1) {
		bankAccount.setAccountType("SAVINGS");
	}
	else {
		cout << "Error: Invalid account type, kindly enter 1 or 2"<<endl;
		return;
	}

	//generate account number
	string prefix = "ACC-";
	string accountNumber = Utility::generateRandom(prefix);
	bankAccount.setAccountNumber(accountNumber);
	bool isOperationSuccessful = Utility::saveBankToFile(bankAccount);
	if (!isOperationSuccessful) {
		throw invalid_argument("Unable to create account");
		return;
	}
	//Display bank account details to customer
	cout << "****Account created, see Account details, kindly select continue as a customer to sign in***" << endl;
	cout << "1. Account Number: " << bankAccount.getAccountNumber() << endl;
	cout << "1. Account Type: " << bankAccount.getAccountType() << endl;
	cout << "2. Surname: " << bankAccount.getSurname() << endl;
	cout << "****************" << endl;
}

/**
* Update account details
* Operation can only be called by an admin
*/
void Operations::updateAccountDetailsOperation() {
	cout << "***Note: You can only modify firstname, email and password" << endl;
	cout << "Kindly enter account number for whish you wish to update details: " << endl;
	string accountNumber;
	cin >> accountNumber;
	Utility::verifyUserInput();
	
	//get account from account number
	BankAccount userAccount= Utility::getBankDetailsFromFile(accountNumber);
	cout << "Account found, Account in view: " << userAccount.getAccountNumber() << endl;

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

	string password;
	cout << "Enter new password you would like to use below otherwise leave blank if you do not wish to change"<< endl;
	getline(cin, password);
	if (password == "") password = userAccount.getPassword();
	userAccount.setPassword(password);

	//Update
	Utility::updateAccountInFile(userAccount);
	cout << "Account updated successfully" << endl;
}

/**
* List all account in bank.txt
* Operation can only be called by an admin
*/
void Operations::showAllAccount() {
	vector<BankAccount> accts = Utility::getAllAccount();
	cout << "****Bank Account List****" << endl;
	for (int i = 0; i<accts.size(); i++) {
		cout << "............." << endl;
		cout <<i+1<< ")Account Number: " << accts[i].getAccountNumber() << " "<<"Account Balance: "<< accts[i].getAccountBalance()<<endl;
	}
	cout << "********" << endl;
	cout << "" << endl;
}