#include "plorg.h"

int main()
{
    Plorg plg = Plorg("Dong Dong");
    plg.SetCI(1003);
    plg.ShowPlorg();

    Plorg plg2;
    plg2.ShowPlorg();

    plg2 = plg;

    plg2.SetCI(123);
    plg2.ShowPlorg();
    plg.ShowPlorg();
    return 0;
}