#pragma once

#include <iostream>
#include "BankAccount.h"


using namespace std;
class Utility
{
public:
	static string generateRandom(string prefix);
	static void saveAccountToFile(BankAccount bankAccount);
	static BankAccount getAccountDetailsFromAccountNumber(string accountNumber);
	static void verifyUserInput();
};

