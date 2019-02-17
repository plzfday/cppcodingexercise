#include <iostream>
#include <cstdlib>      // rand(), srand()의 원형
#include <ctime>        // time()의 원형
#include "vect.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     // 난수 발생기에 씨를 뿌린다
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int trial_num;
    unsigned long min;
    unsigned long max;
    unsigned long total = 0;
    cout << "시도할 횟수를 입력하십시오: ";
    cin >> trial_num;
    cout << "목표 거리를 입력하십시오: ";
    cin >> target;
    cout << "보폭을 입력하십시오: ";
    cin >> dstep;
    for (int i = 0; i < trial_num; ++i)
    {
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "\n" << i + 1 << "번 째 시도\n";
        cout << steps << " 걸음 걸은 후 술고래의 현재 위치:\n";
        cout << result << "\n";;
        result.polar_mode();
        cout << "또는\n" << result << "\n";
        cout << "걸음당 기둥에서 벗어난 평균 거리 = " << result.magval() / steps << "\n";
        if (i == 0)
            min = max = steps;
        else
        {
            if (min > steps)
                min = steps;
            if (max < steps)
                max = steps;
        }
        total += steps;
        steps = 0;
        result.reset(0.0, 0.0);
    }

    cout << "\n" << trial_num << "번 시도했을 때\n";
    cout << "최소 걸음 수: " << min << "\n"
        << "최대 걸음 수: " << max << "\n";
    cout << "평균 걸음 수: " << total / trial_num << "\n";
    cout << "프로그램을 종료합니다.\n";
    return 0;
}
