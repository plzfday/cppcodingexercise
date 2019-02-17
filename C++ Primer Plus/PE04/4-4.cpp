#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string lastName, firstName;
    cout << "퍼스트 네임 (이름)을 입력하시오: ";
    getline(cin, firstName);
    cout << "라스트 네임 (성)을 입력하시오: ";
    getline(cin, lastName);

    string fullName = lastName + ", " + firstName;
    cout << "하나의 문자열로 만들면: " << fullName << endl;
    return 0;
}