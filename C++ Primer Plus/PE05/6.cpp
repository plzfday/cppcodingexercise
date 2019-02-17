#include <iostream>
#include <string>
using namespace std;
int main()
{
    int sale[3]{};
    const char* nameOfYear[] = {
        "Januaray", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };

    for (int j = 1, a; j <= 3; ++j)
    {
        for (int i = 1; i <= 12; ++i)
        {
            cout << j << "년 " << i << "월에 판매한 수량: ";
            cin >> a;
            sale[j - 1] += a;
        }
        cout << j << "년 판매량: " << sale[j - 1] << endl;
    }
    for (int i = 0, sum = 0; i < 3; ++i)
    {
        sum += sale[i];
        cout << i + 1 << "년까지 누적 판매량: " << sum << endl;
    }
    return 0;
}