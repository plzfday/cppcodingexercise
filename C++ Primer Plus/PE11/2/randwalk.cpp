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
    
    cout << "목표 거리를 입력하십시오(끝내려면 q) : ";
    while (cin >> target)
    {
        cout << "보폭을 입력하십시오: ";
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
        cout << steps << " 걸음을 걸은 후 술고래의 현재 위치:\n";
        cout << result << endl;
        result.PolarMode();
        cout << " 또는\n" << result << endl;
        cout << "걸음당 기둥에서 벗어난 평균 거리 = " << result.MagVal() / steps << endl;
        steps = 0;
        result.Reset(0.0, 0.0);
        cout << "목표 거리를 입력하십시오(끝내려면 q) : ";
    }
    cout << "프로그램을 종료합니다.\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}