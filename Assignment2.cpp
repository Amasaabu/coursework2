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
* 2. Since this is a demo application, the admin can login with the password 'admin' 
* 3. Account numbers are randomly generated.
*
*/
int main()
{
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