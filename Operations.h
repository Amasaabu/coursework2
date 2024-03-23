#pragma once
#include "BankAccount.h";
class Operations
{
public:
	static void registerAnAccountOperation();
	static void getAccountDetailsOperation(BankAccount&);
	static void addCashOperation(BankAccount&);
	static void withdrawCashOperation(BankAccount&);
	static void addInterestToAllAccountsOperation();
	static void updateAccountDetailsOperation();
	static void showAllAccount();
	static BankAccount authenticateBankAccount();
};

