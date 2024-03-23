#pragma once

#include <iostream>
#include "BankAccount.h"
#include <vector>

using namespace std;
class Utility
{
public:
	static string generateRandom(string prefix);
	static void verifyUserInput();
	static void addInterestToAllAccount();
	static vector<BankAccount>  getAllAccount();

	static bool saveBankToFile(BankAccount acct);
	static BankAccount getBankDetailsFromFile(string );
	static void updateAccountInFile(BankAccount);
	static bool checkInvalidNumInString(string&);
};

