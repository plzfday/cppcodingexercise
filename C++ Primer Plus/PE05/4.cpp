#include <iostream>
using namespace std;
int main()
{
    int year = 0;
    long double aMoney = 1e5, bMoney = 1e5;
    while (aMoney >= bMoney)
    {
        aMoney += 10000;
        bMoney += bMoney * 0.05;
        year++;
    }
    cout << "It passed " << year << endl;
    cout << "A's money is " << aMoney << endl;
    cout << "B's money is " << bMoney << endl;
    return 0;
}