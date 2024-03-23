#include "Menu.h"
#include "Utility.h"
#include "string";
#include "iostream";
#include "Operations.h"
using namespace std;

void Menu::intialize() {
	while (true) {
		string firstInput = "";
		cout << "*Main Menu*" << endl;
		cout << "Please select an option below: " << endl;
		cout << "1. Continue as a customer" << endl;
		cout << ".........................." << endl;
		cout << "2. Continue as an admin" << endl;
		cout << ".........................." << endl;
		cout << "3. Create a new Bank Account" << endl;
		cout << ".........................." << endl;
		cout << "Enter any other key to exit application" << endl;
		cin >> firstInput;
		Utility::verifyUserInput();
		if (firstInput == "1") {
			initializeCustomerMenu();
		}
		else if (firstInput == "2") {
			initializeAdminMenu();
		}
		else if (firstInput == "3") {
			Operations::registerAnAccountOperation();
		}
		else  {
			return;
		}
	}
}

void Menu::initializeCustomerMenu() {
	BankAccount initializedAccount = Operations::authenticateBankAccount();
	while (true) {
		cout << "Customer Options: " << endl;
		cout << "Kindly enter an option from the list below" << endl;
		cout << "1. View Account Details" << endl;
		cout << "2. Deposit Cash" << endl;
		cout << "3. Withdraw Cash" << endl;
		cout << "4. Sign out and exit to main menu" << endl;
		string secondInput = "";
		cin >> secondInput;
		if (secondInput == "1") {
			Operations::getAccountDetailsOperation(initializedAccount);
		}
		else if (secondInput == "2") {
			Operations::addCashOperation(initializedAccount);
		}
		else if (secondInput == "3") {
			Operations::withdrawCashOperation(initializedAccount);
		}
		else if (secondInput == "4") {
			cout << "Thank you for using this service, see you soon!" << endl;
			return;
		}
		else {
			cout << "An invalid input entered, please try again " << endl;
		}
	}

}

void Menu::initializeAdminMenu() {
	string password = "";
	cout << "Kindly enter admin access password below: " << endl;
	cin >> password;
	Utility::verifyUserInput();
	if (password != "admin") throw exception("Invalid admin password. Because this is a demo app, the password is (admin)");
	while (true) {
		cout << "Admin Options: " << endl;
		cout << "1. To add interest to all account" << endl;
		cout << "2. Modify account details" << endl;
		cout << "3. To see all accounts" << endl;
		cout << "4. To exit to main menu" << endl;
		string secondInput = "";
		cin >> secondInput;
		if (secondInput == "1") {
			Operations::addInterestToAllAccountsOperation();
		}
		else if (secondInput == "2") {
			Operations::updateAccountDetailsOperation();
		}
		else if (secondInput == "3") {
			Operations::showAllAccount();
		}
		else if (secondInput == "4") {
			//cout << "Safely exiting Program..." << endl;
			return;
		}
		else {
			cout << "An invalid input entered, please try again " << endl;
		}
	}
	
}