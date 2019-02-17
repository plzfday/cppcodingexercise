#ifndef VECT_H_
#define VECT_H_
#include <iostream>
namespace vector
{
    class Vector
    {
    public:
        enum Mode { RECT, POL };
    private:
        double x;    // ���� ����
        double y;    // ���� ����
        double mag;  // ������ ����
        double ang;  // ����(��)�� ǥ�õǴ� ������ ����
        Mode mode;   // RECT �Ǵ� POL
        
        void SetMag();
        void SetAng();
        void SetX();
        void SetY();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void Reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double XVal() const { return x; }
        double YVal() const { return y; }
        double MagVal() const { return mag; }
        double AngVal() const { return ang; }
        void PolarMode();
        void RectMode();

    // ������ �����ε�
        Vector operator+(const Vector& b) const;
        Vector operator-(const Vector& b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
    // ������ �Լ�
        friend Vector operator*(double n, const Vector& a);
        friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    // ��ȯ �Լ�
        explicit operator double();
    };
}

#endif // !VECT_H_
