#include <iostream>
#include <string>
using namespace std;
int main()
{
    string firstName, lastName;
    cout << "영문 퍼스트 네임 (이름) : ";
    getline(cin, firstName);
    cout << "영문 라스트 네임 (성) : ";
    getline(cin, lastName);

    cout << "학생이 원하는 학점: ";
    char grade;
    cin >> grade;

    cout << "나이: ";
    int age;
    cin >> age;

    cout << "성명: " << lastName << ", " << firstName << endl;
    cout << "학점: " << char(grade + 1) << endl;
    cout << "나이: " << age;
    return 0;
}