#include <iostream>
#include <string>
using namespace std;

struct Pizza
{
    string mCompanyName;
    double mDiagram;
    double mWeight;
};

int main()
{
    Pizza pizza;
    cout << "회사 이름을 적어주세요: ";
    getline(cin, pizza.mCompanyName);
    cout << "피자의 지름을 알려주세요: ";
    cin >> pizza.mDiagram;
    cout << "피자의 중량을 알려주세요: ";
    cin >> pizza.mWeight;

    cout << "피자 회사 이름: " << pizza.mCompanyName << endl;
    cout << "피자의 지름: " << pizza.mDiagram << endl;
    cout << "피자의 중량: " << pizza.mWeight << endl;
    return 0;
}