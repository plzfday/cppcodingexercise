#include <iostream>
using namespace std;

template<typename T>
T max5(T arr[], size_t size = 5);

int main()
{
    int iArr[5] = { 10, 20, 30, 40, 50 };
    double dArr[5] = { 2.4, 5.6, 201.2, 293.1, 102.2 };
    cout << "int형에서 가장 큰 수: " << max5(iArr) << endl;
    cout << "double형에서 가장 큰 수: " << max5(dArr) << endl;
    return 0;
}

template<typename T>
T max5(T arr[], size_t size)
{
    T ans = arr[0];
    for (int i = 1; i < size; ++i)
        if (ans < arr[i])
            ans = arr[i];
    return ans;
}
