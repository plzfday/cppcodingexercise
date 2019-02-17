#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
    strcpy_s(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    using std::cout;
    using std::cin;

    cout << "ÀÌ¸§: ";
    cin.getline(g.fullname, Len);
    cout << "ÇÚµðÄ¸: ";
    cin >> g.handicap;

    return strlen(g.fullname) ? 1 : 0;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    std::cout << "ÀÌ¸§: " << g.fullname << ", ÇÚµðÄ¸: " << g.handicap << std::endl;
}
