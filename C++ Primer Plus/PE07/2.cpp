#include <iostream>
using namespace std;
const int Max = 10;

int input(double[], int);
void output(double[], int);
double calc_avg(double[], int);

int main()
{
    double scores[Max];
    int input_size = input(scores, Max);
    output(scores, input_size);
    cout << "평균 스코어: " << calc_avg(scores, input_size) << endl;
    return 0;
}

int input(double ar[], int size)
{
    cout << "최대 " << size << "개까지 입력해주십쇼\n";
    double input;
    int i = 0;
    while (i < size && cin >> input)
        ar[i++] = input;
    return i;
}

void output(double ar[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << "#" << (i + 1) << ": " << ar[i] << endl;
}

double calc_avg(double ar[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
        sum += ar[i];
    return sum / size;
}
