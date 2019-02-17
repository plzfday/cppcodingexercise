#include <iostream>

long double probability(unsigned numbers, unsigned picks);
int main()
{
    using namespace std;
    double total, choices;

    cout << "1회자: 전체 수와 뽑을 개수 입력: ";
    if ((cin >> total >> choices) && choices <= total)
    {
        long double firstodds = probability(total, choices);
        cout << "2회자: 전체 수와 뽑을 개수 입력: ";
        if ((cin >> total >> choices) && choices <= total)
        {
            long double secondodds = probability(total, choices);
            cout << "결과: " << firstodds * secondodds << "번 중에 한 번";
        }
    }
    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;
   
    for (n = numbers, p = picks; p > 0; n--, p--)
        result *= n / p;
    return result;
}
