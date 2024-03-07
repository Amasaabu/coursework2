#pragma once

#include <iostream>
#include "BankAccount.h"


using namespace std;
class Utility
{
public:
	static string generateRandom(string prefix);
	//static void saveAccountToFile(BankAccount bankAccount);
	static void saveAccountToFilev1(BankAccount);
	static BankAccount getAccountDetailsFromAccountNumber(string accountNumber);
	static void verifyUserInput();
};

