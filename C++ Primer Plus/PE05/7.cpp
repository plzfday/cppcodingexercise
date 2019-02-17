#include <iostream>
#include <string>
using namespace std;
struct Car
{
    string factory;
    int production_year;
};
int main()
{
    cout << "몇 대의 차를 목록으로 관리하시겠습니까? ";
    int cnt;
    (cin >> cnt).get();
    Car* cars = new Car[cnt];
    for (int i = 0; i < cnt; ++i)
    {
        cout << "자동차 #" << i + 1 << ":\n";
        cout << "제작업체: ";
        getline(cin, cars[i].factory);
        cout << "제작년도: ";
        (cin >> cars[i].production_year).get();
    }
    cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다.\n";
    for (int i = 0; i < cnt; ++i)
    {
        cout << cars[i].production_year << "년형 " << cars[i].factory << endl;
    }
    delete[] cars;
    return 0;
}