#include <iostream>
using namespace std;
int main()
{
    int a = 0, sum = 0;
    do
    {
        sum += a;
        cin >> a;
    } while (a);
    cout << "sum: " << sum;
    return 0;
}