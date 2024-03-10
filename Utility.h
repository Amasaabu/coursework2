#pragma once

#include <iostream>
#include "BankAccount.h"


using namespace std;
class Utility
{
public:
	static string generateRandom(string prefix);
	static void verifyUserInput();
	static void addInterestToAllAccount();

	static bool saveBankToFile(BankAccount acct);
	static BankAccount getBankDetailsFromFile(string );
	static void updateAccountInFile(BankAccount updatedAcct);
};

