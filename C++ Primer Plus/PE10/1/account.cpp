#include <iostream>
#include "account.h"

BankAccount::BankAccount(const std::string & client, const std::string & num, double bal)
{
    name = client;
    acctnum = num;
    balance = bal;
}

void BankAccount::show(void) const
{
    std::cout << "[°í°´ Á¤º¸]\n"
        "¼ºÇÔ: " << name << "\n°èÁÂ¹øÈ£: " << acctnum << "\nÀÜ¾×: " << balance << std::endl;
}

void BankAccount::deposit(double cash)
{
    balance += cash;
}

void BankAccount::withdraw(double cash)
{
    if (balance >= cash)
        balance -= cash;
    else
        std::cout << "ÀÜ¾×ÀÌ ºÎÁ·ÇÕ´Ï´Ù.\n";
}
