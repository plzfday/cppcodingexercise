#include <iostream>
using namespace std;

template<typename T>
T maxn(T arr[], int size);

template<> const char* maxn(const char* arr[], int size);

int main()
{
    int iArr[6] = { 1,2,3,4,5,6 };
    double dArr[4] = { 1.2, 2.4, 3.6, 4.8 };
    const char* str[5] = {
        "Hello this is", 
        "Guten Tag",
        "Aufwiedagen",
        "Nihao ni chi fan le ma", 
        "Annyeong haseyo"
    };
    cout << "int형: " << maxn(iArr, 6) << endl;
    cout << "double형: " << maxn(dArr, 4) << endl;
    cout << "가장 긴 문자열의 주소: " << maxn(str, 5) << endl;
    return 0;
}

template<typename T>
T maxn(T arr[], int size)
{
    T max = arr[0];
    for (int i = 1; i < size; ++i)
        if (max < arr[i])
            max = arr[i];
    return max;
}

template<>
const char * maxn(const char * arr[], int size)
{
    const char* max = arr[0];
    for (int i = 1; i < size; ++i)
        if (strlen(max) < strlen(arr[i]))
            max = arr[i];
    return max;
}
