#include "complex0.h"

complex::complex(double r, double i)
{
    mReal = r;
    mImage = i;
}

complex::~complex()
{
}

complex complex::operator+(const complex& src) const
{
    return complex(mReal + src.mReal, mImage + src.mImage);
}

complex complex::operator-(const complex& src) const
{
    return complex(mReal - src.mReal, mImage - src.mImage);
}

complex complex::operator*(const complex& src) const
{
    return complex(mReal * src.mReal - mImage * src.mImage, mReal * src.mImage + mImage * src.mReal);
}

complex complex::operator*(const double mult) const
{
    return complex(mult * mReal, mult * mImage);
}

complex complex::operator~() const
{
    return complex(mReal, -mImage);
}

complex operator*(const double mult, const complex& src)
{
    return src * mult;
}

std::ostream& operator<<(std::ostream& os, const complex& c)
{
    os << "(" << c.mReal << "," << c.mImage << "i)";
    return os;
}

std::istream& operator>>(std::istream& is, complex & c)
{
    std::cout << "실수부: ";
    if (!(is >> c.mReal))
        return is;

    std::cout << "허수부: ";
    if (!(is >> c.mImage))
        return is;

    return is;
}
