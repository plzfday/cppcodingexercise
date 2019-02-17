#include <iostream>
#include <string>
using namespace std;
int main()
{
    int total = 0;
    const char* nameOfYear[] = {
        "Januaray", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };

    for (int i = 1, a; i <= 12; ++i)
    {
        cout << nameOfYear[i - 1] << ": ";
        cin >> a;
        total += a;
    }
    cout << "한 해 총 판매량: " << total;
    return 0;
}