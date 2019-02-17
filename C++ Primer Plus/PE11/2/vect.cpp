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
    // 1 ���� ���� ������ ����Ͽ���(1 ���ȿ� ���� degree ���� ���)
    const double RAD_TO_DEG = 57.2957795130823;

    Vector::Vector()
    {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            x = n1 * cos(n2 / RAD_TO_DEG);
            y = n1 * sin(n2 / RAD_TO_DEG);
        }
        else
        {
            cout << "Vector()�� ���޵� ��3�� �Ű������� �߸��Ǿ���.\n";
            cout << "�׷��� ���͸� 0���� �����Ͽ���.\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    void Vector::Reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            x = n1 * cos(n2 / RAD_TO_DEG);
            y = n1 * sin(n2 / RAD_TO_DEG);
        }
        else
        {
            cout << "Vector()�� ���޵� ��3�� �Ű������� �߸��Ǿ���.\n";
            cout << "�׷��� ���͸� 0���� �����Ͽ���.\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector()
    {
    }

    double Vector::MagVal() const
    {
        return sqrt(x * x + y * y);
    }

    double Vector::AngVal() const
    {
        if (x == 0.0 && y == 0.0)
            return 0.0;
        else
            return atan2(y, x);
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

    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
            os << "(x, y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
            os << "(m, a) = (" << v.MagVal() << ", " << v.AngVal() * RAD_TO_DEG << ")";
        else
            os << "Vector ��ü�� ��� ������ Ʋ�Ƚ��ϴ�.\n";
        return os;
    }

}

