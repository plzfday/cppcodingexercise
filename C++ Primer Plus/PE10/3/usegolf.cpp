#include <iostream>
#include "golf.h"

int main()
{
    Golf ann("Ann Birdfree", 24);
    Golf andy;
    andy.SetGolf();
    ann.ShowGolf();
    andy.ShowGolf();
    return 0;
}