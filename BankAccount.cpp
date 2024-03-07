#include "BankAccount.h"
#include <iostream>
#include <string>
using namespace std;

int BankAccount::getBirthDate() {
	return this->birthDate;
}

void BankAccount::setBirthDate(int val) {
	this->birthDate = val;
}

int BankAccount::getPhone()
{
	return this->phone;
}

void BankAccount::setPhone(int val)
{
	this->phone=val;
}



//CONSTRUCTORS
//BankAccount::BankAccount() {
//	 birthMonth=0;
//	birthDate=0;
//	birthYear=0;
//
//	 accountNumber="";
//	 email="";
//	 phoneNumber="";
//	 surname="";
//	 firstname="";
//	 accountBalance=0;
//
//}
//
//
//void BankAccount::setBirthDate(int birthDate) {
//	/*if (birthDate < 1 || birthDate>31) {
//		throw invalid_argument("Invalid birth date entered, value must be between 1 and 31");
//	}*/
//	this->birthDate = birthDate;
//}
//
//int BankAccount::getBirthDate() {
//	return this->birthDate;
//}
//
//void BankAccount::setBirthMonth(int birthMonth) {
//	//if (birthMonth < 1 || birthMonth>12) {
//	//	throw invalid_argument("Invalid birth month entered, value must be between 1 and 12");
//	//}
//	this->birthMonth = birthMonth;
//}
//int BankAccount::getBirthMonth() {
//	return this->birthMonth;
//}
//
//void BankAccount::setBirthYear(int birthYear) {
//	this->birthYear = birthYear;
//}
//int BankAccount::getBirthYear() {
//	//if (birthDate < 0001 || birthDate>9999) {
//	//	throw invalid_argument("Invalid birth year entered, value must be between 1 and 31");
//	//}
//	return this->birthYear;
//}
//
//string BankAccount::getAccountNumber()
//{
//	return this->accountNumber;
//}
//
//void BankAccount::setAccountNumber(string accountNumber)
//{
//	this->accountNumber = accountNumber;
//}
//
//void BankAccount::setEmail(string email)
//{
//	this->email = email;
//}
//string BankAccount::getEmail()
//{
//	return  this->email;
//}
//
//void BankAccount::setPhoneNumber(string phoneNumber)
//{
//	this->phoneNumber = phoneNumber;
//}
//string BankAccount::getPhoneNumber()
//{
//	return this->phoneNumber;
//}
//
//void BankAccount::setFirstName(string firstName)
//{
//	this->firstname = firstName;
//}
//string BankAccount::getFirstName()
//{
//	return this->firstname;
//}
//
//void BankAccount::setSurname(string surname)
//{
//	this->surname = surname;
//}
//string BankAccount::getSurname()
//{
//	return this->surname;
//}
//
//
//void BankAccount::setAccountBalance(double amount)
//{
//	this->accountBalance = amount;
//}
//
//
//double BankAccount::getAccountBalance()
//{
//	return this->accountBalance;
//}

