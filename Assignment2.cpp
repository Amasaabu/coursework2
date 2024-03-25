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
* 1. The app stores bank accounts in a bank.txt file
* 2. The bank.txt would be created once a bank account is created
* 3. Once the program is started for the first time, kindly register a new customer first (by selecting the option from the main menu)
* 4. To login as an admin the password to be entered is 'admin'
* 5. Account numbers are randomly generated.
* 6. I assumed creating an account is same as creating a new customer.
* 7. For a customer to login kindly select continue as a customer
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