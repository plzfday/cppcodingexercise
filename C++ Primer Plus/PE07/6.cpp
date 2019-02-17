#include <iostream>
using namespace std;

unsigned Fill_array(double ar[], unsigned size);
void Show_array(double ar[], unsigned size);
void Reverse_array(double ar[], unsigned size);

int main()
{
    double array[10];
    Fill_array(array, 10);
    Show_array(array, 10);
    Reverse_array(array, 10);
    Show_array(array, 10);
    Reverse_array(array + 1, 8);
    Show_array(array, 10);
    return 0;
}

unsigned Fill_array(double ar[], unsigned size)
{
    double input;
    int i = 0;
    while (i < size && (cin >> input))
        ar[i++] = input;
    return i;
}

void Show_array(double ar[], unsigned size)
{
    for (int i = 0; i < size; ++i)
        cout << ar[i] << " ";
    cout << endl;
}

void Reverse_array(double ar[], unsigned size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        int temp = ar[i];
        ar[i] = ar[size - i - 1];
        ar[size - i - 1] = temp;
    }
}
