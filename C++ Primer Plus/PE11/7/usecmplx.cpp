#include <iostream>
#include "complex0.h"

using namespace std;

int main()
{
    complex a(3.0, 4.0);
    complex c;
    cout << "�ϳ��� ���Ҽ��� �Է��Ͻʽÿ�(�������� q):\n";
    while (cin >> c)
    {
        cout << "c = " << c << '\n';
        cout << "���׺��Ҽ� = " << ~c << '\n';
        cout << "a = " << a << '\n';
        cout << "a + c = " << a + c << '\n';
        cout << "a - c = " << a - c << '\n';
        cout << "a * c = " << a * c << '\n';
        cout << "2 * c = " << 2 * c << '\n';
        cout << "c * 2 = " << c * 2 << '\n';
        cout << "�ϳ��� ���Ҽ��� �Է��Ͻʽÿ�(�������� q):\n";
    }
    cout << "���α׷��� �����մϴ�.\n";
    return 0;
}