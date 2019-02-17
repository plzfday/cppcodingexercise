#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
public:
    enum Mode { STONE, POUND_INT, POUND_DOUBLE };
private:
    enum { LBS_PER_STN = 14 };  // STONE PER POUND
    Mode mode;                 
    int stone;                  // ������(����)
    double pds_left;            // �Ҽ���(�Ŀ��) 
    double pounds;              // �Ŀ��� ��Ÿ�� ��ü ����
public:
    Stonewt(double lbs, Mode m = STONE);
    Stonewt(int stn, double lbs, Mode m = STONE);
    Stonewt();
    ~Stonewt();
    void SetMode(Mode m);
    Stonewt operator+(const Stonewt & st) const;
    Stonewt operator-(const Stonewt & st) const;
    Stonewt operator*(const Stonewt & st) const;

    bool operator==(const Stonewt & st) const;
    bool operator!=(const Stonewt & st) const;
    bool operator>(const Stonewt & st) const;
    bool operator<(const Stonewt & st) const;
    bool operator>=(const Stonewt & st) const;
    bool operator<=(const Stonewt & st) const;

    friend std::ostream & operator<<(std::ostream & os, const Stonewt & st);
};
#endif // !STONEWT_H_
