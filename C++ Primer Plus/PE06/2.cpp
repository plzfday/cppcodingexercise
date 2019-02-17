#include <iostream>
#include <cstdlib>
using namespace std;
const int SIZE = 10;
int main()
{
    double donation[SIZE];
    double sum = 0;
    int moreThanAVG = 0;

    int i = 0;
    double input;
    do
    {
        cin >> input;
        if (cin.fail())
            exit(EXIT_FAILURE);
        sum += input;
        donation[i] = input;
    } while (++i < SIZE);

    double avg = sum / i;

    for (int j = 0; j < i; ++j)
        if (donation[j] > avg)
            ++moreThanAVG;
    cout << "기부금들의 평균: " << avg << "\n평균보다 큰 기부금의 개수: " << moreThanAVG << endl;
    return 0;
}