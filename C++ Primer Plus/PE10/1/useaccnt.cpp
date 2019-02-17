#include <iostream>
#include "account.h"

int main()
{
    BankAccount acc1("James watson", "1234-5678", 3000);
    acc1.show();
    acc1.deposit(2000);
    acc1.show();
    acc1.withdraw(5000);
    acc1.withdraw(1000);
    acc1.show();
    return 0;
}