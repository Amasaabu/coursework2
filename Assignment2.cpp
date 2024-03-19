// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include "Menu.h"

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
	try {
		Menu::intialize();
		cout << "Application exiting..."<<endl;
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
}