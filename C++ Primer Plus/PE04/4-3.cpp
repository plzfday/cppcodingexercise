#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char lastName[20], firstName[20];
    cout << "퍼스트 네임 (이름)을 입력하시오: ";
    cin.getline(firstName, 20);
    cout << "라스트 네임 (성)을 입력하시오: ";
    cin.getline(lastName, 20);

    const char* fullName = strcat(strcat(lastName, ", "), firstName);
    cout << "하나의 문자열로 만들면: " << fullName << endl;
    return 0;
}