#pragma once

#include <iostream>
#include "BankAccount.h"


using namespace std;
class Utility
{
public:
	static string generateRandom(string prefix);
	static void verifyUserInput();
	void addInterestToAllAccount();

	static bool saveBankToFile(BankAccount acct);
	static BankAccount getBankDetailsFromFile(string );
	static bool  updateAccountInFile(BankAccount updatedAcct);
};

