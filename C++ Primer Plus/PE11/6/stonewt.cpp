#include <iostream>
#include "stonewt.h"

Stonewt::Stonewt(double lbs, Mode m)
{
    mode = m;
    stone = int(lbs) / LBS_PER_STN;
    pds_left = int(lbs) % LBS_PER_STN + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs, Mode m)
{
    mode = m;
    stone = stn;
    pds_left = lbs;
    pounds = stone * LBS_PER_STN + lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{
}

void Stonewt::SetMode(Mode m)
{
    mode = m;
}

Stonewt Stonewt::operator+(const Stonewt & st) const
{
    return Stonewt(pounds + st.pounds);
}

Stonewt Stonewt::operator-(const Stonewt & st) const
{
    return Stonewt(pounds - st.pounds);
}

Stonewt Stonewt::operator*(const Stonewt & st) const
{
    return Stonewt(pounds * st.pounds);
}

bool Stonewt::operator==(const Stonewt & st) const
{
    return pounds == st.pounds;
}

bool Stonewt::operator!=(const Stonewt & st) const
{
    return pounds != st.pounds;
}

bool Stonewt::operator>(const Stonewt & st) const
{
    return pounds > st.pounds;
}

bool Stonewt::operator<(const Stonewt & st) const
{
    return pounds < st.pounds;
}

bool Stonewt::operator>=(const Stonewt & st) const
{
    return pounds >= st.pounds;
}

bool Stonewt::operator<=(const Stonewt & st) const
{
    return pounds <= st.pounds;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & st)
{
    if (st.mode == Stonewt::STONE)
        os << st.stone << "스톤, " << st.pds_left << "파운드\n";
    else if (st.mode == Stonewt::POUND_INT)
        os << int(st.pounds) << "파운드\n";
    else if (st.mode == Stonewt::POUND_DOUBLE)
        os << st.pounds << "파운드\n";
    else
        os << "Stonewt 객체 모드 지정이 틀렸습니다.\n";
    return os;
}
