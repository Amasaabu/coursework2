#pragma once

#include <iostream>
#include "BankAccount.h"
#include <vector>

using namespace std;
class Utility
{
public:
	static string generateRandom(string&);
	static void verifyUserInput();
	static void addInterestToAllAccount();
	static vector<BankAccount>  getAllAccount();

	static bool saveBankToFile(BankAccount&);
	static BankAccount getBankDetailsFromFile(string&);
	static void updateAccountInFile(BankAccount&);
};

