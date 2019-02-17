#include <cmath>
#include "vect.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace vector
{
    // 1 라디안 내의 각도를 계산하여라(1 라디안에 대한 degree 값을 계산)
    const double RAD_TO_DEG = 57.2957795130823;

    void Vector::SetMag()
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::SetAng()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    void Vector::SetX()
    {
        x = mag * cos(ang);
    }

    void Vector::SetY()
    {
        y = mag * sin(ang);
    }

    Vector::Vector()
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            SetMag();
            SetAng();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / RAD_TO_DEG;
            SetX();
            SetY();
        }
        else
        {
            cout << "Vector()에 전달된 제3의 매개변수가 잘못되었다.\n";
            cout << "그래서 벡터를 0으로 설정하였다.\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    void Vector::Reset(double n1, double n2, Mode form)
    {
        mode = form;
        if(form == RECT)
        {
            x = n1;
            y = n2;
            SetMag();
            SetAng();
        }
        else if (form == POL)
        {
        mag = n1;
        ang = n2 / RAD_TO_DEG;
        SetX();
        SetY();
        }
        else
        {
        cout << "Vector()에 전달된 제3의 매개변수가 잘못되었다.\n";
        cout << "그래서 벡터를 0으로 설정하였다.\n";
        x = y = mag = ang = 0.0;
        mode = RECT;
        }
    }

    Vector::~Vector()
    {
    }

    void Vector::PolarMode()
    {
        mode = POL;
    }

    void Vector::RectMode()
    {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.x);
    }

    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    Vector::operator double()
    {
        return mag;
    }

    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
            os << "(x, y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
            os << "(m, a) = (" << v.mag << ", " << v.ang * RAD_TO_DEG << ")";
        else
            os << "Vector 객체의 모드 지정이 틀렸습니다.\n";
        return os;
    }

}

