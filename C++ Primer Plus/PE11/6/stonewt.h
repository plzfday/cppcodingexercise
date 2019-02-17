#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
public:
    enum Mode { STONE, POUND_INT, POUND_DOUBLE };
private:
    enum { LBS_PER_STN = 14 };  // STONE PER POUND
    Mode mode;                 
    int stone;                  // 정수부(스톤)
    double pds_left;            // 소수부(파운드) 
    double pounds;              // 파운드로 나타낸 전체 무게
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
