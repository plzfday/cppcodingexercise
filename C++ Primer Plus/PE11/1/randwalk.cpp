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

    ofstream filewriter;
    filewriter.open("./report.txt");
    if (!filewriter.is_open())
        return 0;
    
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

            filewriter << steps << ": " << result << endl;
            cout << steps << ": " << result << endl;
            steps++;
        }
        filewriter << steps << " ������ ���� �� ������ ���� ��ġ:\n";
        cout << steps << " ������ ���� �� ������ ���� ��ġ:\n";
        filewriter << result << endl;
        cout << result << endl;
        result.PolarMode();
        filewriter << " �Ǵ�\n" << result << endl;
        cout << " �Ǵ�\n" << result << endl;
        filewriter << "������ ��տ��� ��� ��� �Ÿ� = " << result.MagVal() / steps << endl;
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