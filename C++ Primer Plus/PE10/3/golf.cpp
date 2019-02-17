#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf(const char * name, int hc)
{
    strcpy_s(mFullName, name);
    mHandicap = hc;
}

int Golf::SetGolf()
{
    using std::cout;
    using std::cin;

    cout << "ÀÌ¸§: ";
    cin.getline(mFullName, LEN);
    cout << "ÇÚµðÄ¸: ";
    cin >> mHandicap;

    return strlen(mFullName) ? 1 : 0;
}

void Golf::Handicap(int hc)
{
    mHandicap = hc;
}

void Golf::ShowGolf() const
{
    std::cout << "ÀÌ¸§: " << mFullName << ", ÇÚµðÄ¸: " << mHandicap << std::endl;
}