#include <iostream>
#include <cstring>

#include "plorg.h"

Plorg::Plorg(const char * str)
{
    strcpy_s(mName, str);
    mCI = 50;
}

void Plorg::SetCI(int ci)
{
    mCI = ci;
}

void Plorg::ShowPlorg() const
{
    std::cout << "Name: " << mName << ", CI: " << mCI << std::endl;
}
