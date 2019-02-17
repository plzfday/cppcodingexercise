#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "출력할 행 수를 입력하십시오: ";
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n - i; ++j)
            cout << '.';
        for (int j = 1; j <= i; ++j)
            cout << '*';
        cout << '\n';
    }
}