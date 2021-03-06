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
        double x;    // 수평 성분
        double y;    // 수직 성분
        Mode mode;   // RECT 또는 POL
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void Reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double XVal() const { return x; }
        double YVal() const { return y; }
        double MagVal() const;
        double AngVal() const;
        void PolarMode();
        void RectMode();

    // 연산자 오버로딩
        Vector operator+(const Vector& b) const;
        Vector operator-(const Vector& b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
    // 프렌드 함수
        friend Vector operator*(double n, const Vector& a);
        friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    };
}

#endif // !VECT_H_
