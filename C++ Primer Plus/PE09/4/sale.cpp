#include <iostream>
#include "sale.h"

void SALES::setSales(Sales & s, const double ar[], int n)
{
    int sz = n < QUARTERS ? n : QUARTERS;
    double sum = 0.0;
    double max = ar[0];
    double min = ar[0];

    for (int i = 0; i < sz; ++i)
    {
        s.sales[i] = ar[i];
        sum += ar[i];

        if (max < ar[i])
            max = ar[i];
        if (min > ar[i])
            min = ar[i];
    }
    for (int i = sz; i < QUARTERS; ++i)
        s.sales[i] = 0;
    s.average = sum / sz;
    s.max = max;
    s.min = min;    
}

void SALES::setSales(Sales & s)
{
    using std::cout;
    using std::cin;

    double sum = 0.0;
    for (int i = 0; i < 4; ++i)
    {
        cout << i + 1 << "ºÐ±â ÆÇ¸Å¾×: ";
        cin >> s.sales[i];
        sum += s.sales[i];
    }

    double max = s.sales[0], min = s.sales[0];
    for (int i = 1; i < 4; ++i)
    {
        if (max < s.sales[i])
            max = s.sales[i];
        if (min > s.sales[i])
            min = s.sales[i];
    }
    s.average = sum / QUARTERS;
    s.max = max;
    s.min = min;
}

void SALES::showSales(const Sales & s)
{
    using namespace std;
    for (int i = 0; i < QUARTERS; ++i)
        cout << s.sales[i] << " ";
    cout << endl;
    cout << "Æò±Õ°ª: " << s.average << endl;
    cout << "ÃÖ´ñ°ª: " << s.max << endl;
    cout << "ÃÖ¼Ú°ª: " << s.min << endl;
}
