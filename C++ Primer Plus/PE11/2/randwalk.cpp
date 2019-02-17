#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main()
{
    using namespace std;
    using vector::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    
    cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q) : ";
    while (cin >> target)
    {
        cout << "������ �Է��Ͻʽÿ�: ";
        if (!(cin >> dstep))
            break;

        while (result.MagVal() < target)
        {
            direction = rand() % 360;
            step.Reset(dstep, direction, Vector::POL);
            result = result + step;

            cout << steps << ": " << result << endl;
            steps++;
        }
        cout << steps << " ������ ���� �� ������ ���� ��ġ:\n";
        cout << result << endl;
        result.PolarMode();
        cout << " �Ǵ�\n" << result << endl;
        cout << "������ ��տ��� ��� ��� �Ÿ� = " << result.MagVal() / steps << endl;
        steps = 0;
        result.Reset(0.0, 0.0);
        cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q) : ";
    }
    cout << "���α׷��� �����մϴ�.\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}