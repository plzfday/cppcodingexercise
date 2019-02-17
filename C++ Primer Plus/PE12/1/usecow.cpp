#include <iostream>
#include "cow.h"
using namespace std;

int main()
{
    Cow v1;
    Cow v2("Dong Dong", "Soccer", 12.4);
    Cow v3(v2);
    Cow v4("Min Ng", "Football", 100.3);
    
    cout << "Before:\n";
    v4.ShowCow();
    v4 = v2;

    cout << "After:\n";
    v4.ShowCow();

    cout << "------------------\n";
    v1.ShowCow();
    v2.ShowCow();
    v3.ShowCow();
    return 0;
}