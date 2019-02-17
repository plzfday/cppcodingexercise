#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class complex
{
private:
    double mReal;
    double mImage;
public:
    complex(double r = 0.0, double i = 0.0);
    ~complex();

    complex operator+(const complex& src) const;
    complex operator-(const complex& src) const;
    complex operator*(const complex& src) const;
    complex operator*(const double mult) const;
    complex operator~() const;

    friend complex operator*(const double mult, const complex& src);
    friend std::ostream& operator<<(std::ostream& os, const complex& c);
    friend std::istream& operator>>(std::istream& is, complex& c);
};

#endif // !COMPLEX0_H_
