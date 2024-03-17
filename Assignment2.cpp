// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include "Operations.h"
using namespace  std;



/**
* Name: Abubakar Amasa
* Assignment 2
* Assumptions Made:
* 1. Applications begins by expecting user to either continue as an admin or a customer
* 2. Options available for an admin are:
*	a. Add interest to all account opened
*	b. See all account numbers and their balance
* 3. Options available for a customer:
*	a. Create a new account
*	b. View account details
*	c. withdraw cash
*	d. Deposit cash
*	e. Update account details
* 
* 4. All account are stored in text file (bank.txt)
* 5. Accounts can be either savings or current
* 
*
*/

int main()
{
	srand((unsigned)time(NULL));

	bool isValidInput = true;
	string firstInput = "";
	do {
		cout << "Welcome to Banking app" << endl;
		cout << "Please select an option below: " << endl;
		cout << "1. Continue as a customer" << endl;
		cout << "2. Continue as an admin" << endl;
		cin >> firstInput;
		try
		{
			// Login Mode (Customer)
			if (firstInput == "1") {
				cout << "Customer Options: " << endl;
				cout << "Kindly enter an option from the list below" << endl;
				cout << "1. Register a new account" << endl;
				cout << "2. View Account Details" << endl;
				cout << "3. Deposit Cash" << endl;
				cout << "4. Withdraw Cash" << endl;
				cout << "5. To exit the preogram" << endl;
				string secondInput = "";
				cin >> secondInput;
				if (secondInput == "1") {
					Operations::registerAnAccountOperation();
					continue;

				}
				else if (secondInput == "2") {
					Operations::getAccountDetailsOperation();
					continue;
				}
				else if (secondInput == "3") {
					Operations::addCashOperation();
					continue;
				}
				else if (secondInput == "4") {
					Operations::withdrawCashOperation();
					continue;
				}
				else if (secondInput == "5") {
					cout << "Safely exiting Program..." << endl;
					return 0;
				}
				else {
					cout << "An invalid input entered, please try again " << endl;
					continue;
				}
			}
			else if (firstInput == "2") { // LOGIN MODE (Admin)
				cout << "Admin Options: " << endl;
				cout << "1. To add interest to all account" << endl;
				cout << "2. Modify account details" << endl;
				cout << "3. To exit the program" << endl;
				string secondInput = "";
				cin >> secondInput;
				if (secondInput == "1") {
					Operations::addInterestToAllAccountsOperation();
					continue;
				}
				else if (secondInput == "2") {
					Operations::updateAccountDetailsOperation();
				}
				else if (secondInput == "3") {
					cout << "Safely exiting Program..." << endl;
					return 0;
				}
				else {
					cout << "An invalid input entered, please try again " << endl;
					continue;
				}
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

		catch (const std::exception& e)
		{
			cout << e.what() << endl;
			cout << "An exception occured" << endl;
		}

	} while (isValidInput);
}