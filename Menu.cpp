#include "Menu.h"

#include "string";
#include "iostream";
#include "Operations.h"
using namespace std;

void Menu::intialize() {
	while (true) {
		string firstInput = "";
		cout << "Welcome to Banking app" << endl;
		cout << "Please select an option below: " << endl;
		cout << "1. Continue as a customer" << endl;
		cout << "2. Continue as an admin" << endl;
		cout << "Enter any other key to exit application" << endl;
		cin >> firstInput;
		if (firstInput == "1") {
			initializeCustomerMenu();
		}
		else if (firstInput == "2") {
			initializeAdminMenu();
		}
		else if (firstInput == "3") {
			return;
		}
	}
}

void Menu::initializeCustomerMenu() {
	cout << "Customer Options: " << endl;
	cout << "Kindly enter an option from the list below" << endl;
	cout << "1. Register a new account" << endl;
	cout << "2. View Account Details" << endl;
	cout << "3. Deposit Cash" << endl;
	cout << "4. Withdraw Cash" << endl;
	cout << "5. To exit to main menu" << endl;
	string secondInput = "";
	cin >> secondInput;
	if (secondInput == "1") {
		Operations::registerAnAccountOperation();

	}
	else if (secondInput == "2") {
		Operations::getAccountDetailsOperation();
	}
	else if (secondInput == "3") {
		Operations::addCashOperation();
	}
	else if (secondInput == "4") {
		Operations::withdrawCashOperation();
	}
	else if (secondInput == "5") {
		//cout << "Safely exiting Program..." << endl;
		return;
	}
	else {
		cout << "An invalid input entered, please try again " << endl;
	}
}

void Menu::initializeAdminMenu() {
	cout << "Admin Options: " << endl;
	cout << "1. To add interest to all account" << endl;
	cout << "2. Modify account details" << endl;
	cout << "3. To exit to main menu" << endl;
	string secondInput = "";
	cin >> secondInput;
	if (secondInput == "1") {
		Operations::addInterestToAllAccountsOperation();
	}
	else if (secondInput == "2") {
		Operations::updateAccountDetailsOperation();
	}
	else if (secondInput == "3") {
		//cout << "Safely exiting Program..." << endl;
		return;
	}
	else {
		cout << "An invalid input entered, please try again " << endl;
	}
}