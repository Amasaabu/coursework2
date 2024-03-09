#pragma once

#include <iostream>
#include "BankAccount.h"


using namespace std;
class Utility
{
public:
	static string generateRandom(string prefix);
	static bool saveAccountToFile(BankAccount bankAccount);
	static BankAccount getAccountDetailsFromAccountNumber(string accountNumber);
	static void verifyUserInput();

	static bool saveBankToArray(BankAccount acct);
	static BankAccount getBankDetailsFromFile(string accountNumber);
};

