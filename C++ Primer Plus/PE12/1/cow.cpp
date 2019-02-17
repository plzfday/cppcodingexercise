#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow()
{
    std::strcpy(name, "");
    hobby = new char[2];
    std::strcpy(hobby, "");
    weight = 0.0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    std::strcpy(name, nm);
    hobby = new char[std::strlen(ho) + 1];
    std::strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c)
{
    std::strcpy(name, c.name);
    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete[] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
    std::strcpy(name, c.name);
    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const
{
    std::cout << "Name: " << name << "\nHobby: " << hobby << "\nWeight: " << weight << std::endl;
}
