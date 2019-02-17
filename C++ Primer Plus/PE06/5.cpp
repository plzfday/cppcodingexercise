#include <iostream>
using namespace std;
int main()
{
    double income;
    double tax;

    cout << "소득을 입력하십시오: ";
    while (cin >> income && income >= 0)
    {
        if (income <= 5000)
            tax = 0.0;
        else if (income <= 15000)
            tax = (income - 5000) * 0.1;
        else if (income <= 35000)
            tax = 10000 * 0.1 + (income - 15000) * 0.15;
        else
            tax = 10000 * 0.1 + 20000 * 0.15 + (income - 35000) * 0.2;
        cout << "소득세는 " << tax << "입니다.\n";
        cout << "소득을 입력하십시오: ";
    }
    return 0;
}
