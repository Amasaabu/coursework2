// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include "Menu.h"

using namespace  std;



/**
* Name: Abubakar Amasa
* Assignment 2 
* Brief Note:
* 1. The app stores all bank accounts in a bank.txt file i.e an array of accounts in a single text file.
* 2. If no bank.txt file exists initially,it would be created once a bank account is created
* 3. Once the program is started for the first time, kindly register a new customer first (by selecting the option from the main menu)
* 4. To login as an admin the password to be entered is 'admin'. (without the quote)
* 5. An admin has the ability to view all account and modify some account details for customers (such as change password)
* 6. An admin has the ability to add interest to all account on the bank.txt file
* 7. Account numbers are randomly generated.
* 8. I assumed creating an account is same as creating a new customer.
* 9. For a customer to login kindly select continue as a customer
*
*/
int main()
{
	//initialize srand to generate random numbers
	srand((unsigned)time(NULL));
	bool menuExitedSuccessfully = false;
	while (!menuExitedSuccessfully){
		try {
			Menu::intialize();
			// if we get here it means all went well in menu initialization, and we can safely exit the program
			menuExitedSuccessfully = true;
		}
		catch (invalid_argument& e) {
			cerr << e.what() << endl;
			cout << "Kindly try again" << endl;
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
			cout << "Kindly try again" << endl;
		}
	}

}