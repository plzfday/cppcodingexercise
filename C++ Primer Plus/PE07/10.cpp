#include <iostream>
using namespace std;

typedef double(*pf)(double, double);

double calculate(double a1, double a2, pf function);
double add(double x, double y);
double mult(double x, double y);
double sub(double x, double y);
double div(double x, double y);

int main()
{
    pf set[4] = { add, sub, mult, div };
    double p1, p2;
    double array[4];

    cout << "x와 y를 입력하십시오(끝내려면 q를 입력): ";
    while (cin >> p1 >> p2)
    {
        for (int i = 0; i < 4; ++i)
            array[i] = calculate(p1, p2, set[i]);

        cout << "x + y = " << array[0] << endl;
        cout << "x - y = " << array[1] << endl;
        cout << "x * y = " << array[2] << endl;
        cout << "x / y = " << array[3] << endl << endl;

        cout << "x와 y를 입력하십시오(끝내려면 q를 입력): ";
    }
    return 0;
}

double calculate(double a1, double a2, pf function)
{
    return function(a1, a2);
}

double add(double x, double y)
{
    return x + y;
}

double mult(double x, double y)
{
    return x * y;
}

double sub(double x, double y)
{
    return x - y;
}

double div(double x, double y)
{
    return x / y;
}
