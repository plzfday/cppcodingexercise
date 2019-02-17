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
    std::cout << "[�� ����]\n"
        "����: " << name << "\n���¹�ȣ: " << acctnum << "\n�ܾ�: " << balance << std::endl;
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
        std::cout << "�ܾ��� �����մϴ�.\n";
}
