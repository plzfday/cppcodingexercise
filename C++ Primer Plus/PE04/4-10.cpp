#include <array>
#include <iostream>
int main()
{
    using namespace std;
    array<double, 3> records;

    cout << "1차 시도: ";
    cin >> records[0];
    cout << "2차 시도: ";
    cin >> records[1];
    cout << "3차 시도: ";
    cin >> records[2];

    double sum = records[0] + records[1] + records[2];

    cout << "횟수: 3, 평균: " << sum / 3.0 << endl;
    return 0;
}