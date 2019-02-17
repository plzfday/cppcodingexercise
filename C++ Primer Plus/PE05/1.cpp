#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    long double ans = (b - a + 1) / 2.0 * (a + b);
    cout << ans;
    return 0;
}