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
    Pizza* pizza = new Pizza;
    cout << "피자의 지름을 알려주세요: ";
    (cin >> pizza->mDiagram).get(); // cin >> pizza->mDiagram 후에 개행 문자가 입력 큐에 남는데
    cout << "회사 이름을 적어주세요: ";
    getline(cin, pizza->mCompanyName); // getline은 그걸 받아버리기 때문에 문제가 생길 수 있다.
    cout << "피자의 중량을 알려주세요: ";
    cin >> pizza->mWeight;

    cout << "피자 회사 이름: " << pizza->mCompanyName << endl;
    cout << "피자의 지름: " << pizza->mDiagram << endl;
    cout << "피자의 중량: " << pizza->mWeight << endl;
	
	delete pizza;
    return 0;
}