#include <iostream>
#include "namesp.h"

int main()
{
    using namespace SALES;
    using namespace std;

    double ar[QUARTERS] = { 1.0,2.0,3.0,4.0 };
    Sales tmp1 = Sales(ar, QUARTERS);
    tmp1.ShowSales();
    Sales tmp2;
    tmp2.SetSales();
    tmp2.ShowSales();
    return 0;
}