#include <iostream>
#include "stack.h"

int main()
{
    using namespace std;
    Stack stk;
    stk.Push({ "Dongyeon Park", 3000.0 });

    Customer customer1;
    stk.Pop(customer1);
    cout << customer1.FullName << " " << customer1.Payment << endl;
    return 0;
}