#include <iostream>
using namespace std;

double harmonic_mean(double x, double y)
{
    return 2.0 * x * y / (x + y);
}

int main()
{
    double x, y;
    cout << "두 수를 입력하세요(0이 들어가면 종료): ";
    while (cin >> x >> y) {
        if (!x || !y)
            break;
        cout << harmonic_mean(x, y) << endl;
        cout << "두 수를 입력하세요(0이 들어가면 종료): ";
    }
    cout << "프로그램을 종료합니다.\n";
    return 0;
}