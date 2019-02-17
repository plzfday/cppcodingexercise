#include <iostream>
using namespace std;

double factorial(unsigned n);

int main()
{
    int n;
    while (cin >> n)
        cout << n << "! = " << factorial(n) << endl;
    return 0;
}

double factorial(unsigned n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
