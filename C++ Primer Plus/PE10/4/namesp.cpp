#include <iostream>
#include "namesp.h"

SALES::Sales::Sales()
{
    for (auto i : mSales)
        i = 0.0;
    mAverage = mMax = mMin = 0.0;
}

SALES::Sales::Sales(const double ar[], int n)
{
    int sz = n < QUARTERS ? n : QUARTERS;
    double sum = 0.0;
    double max = ar[0];
    double min = ar[0];

    for (int i = 0; i < sz; ++i)
    {
        mSales[i] = ar[i];
        sum += ar[i];

        if (max < ar[i])
            max = ar[i];
        if (min > ar[i])
            min = ar[i];
    }
    for (int i = sz; i < QUARTERS; ++i)
        mSales[i] = 0;
    mAverage = sum / sz;
    mMax = max;
    mMin = min;
}

void SALES::Sales::SetSales()
{
    using std::cout;
    using std::cin;

    double sum = 0.0;
    for (int i = 0; i < 4; ++i)
    {
        cout << i + 1 << "ºÐ±â ÆÇ¸Å¾×: ";
        cin >> mSales[i];
        sum += mSales[i];
    }

    double max = mSales[0], min = mSales[0];
    for (int i = 1; i < 4; ++i)
    {
        if (max < mSales[i])
            max = mSales[i];
        if (min > mSales[i])
            min = mSales[i];
    }
    mAverage = sum / QUARTERS;
    mMax = max;
    mMin = min;
}

void SALES::Sales::ShowSales() const
{
    using namespace std;
    for (int i = 0; i < QUARTERS; ++i)
        cout << mSales[i] << " ";
    cout << endl;
    cout << "Æò±Õ°ª: " << mAverage << endl;
    cout << "ÃÖ´ñ°ª: " << mMax << endl;
    cout << "ÃÖ¼Ú°ª: " << mMin << endl;
}
