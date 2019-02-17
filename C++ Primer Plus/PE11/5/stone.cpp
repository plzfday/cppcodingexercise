#include <iostream>
#include "stonewt.h"

using std::cout;

int main()
{
    Stonewt stn1(99.2);
    Stonewt stn2(30.9, Stonewt::STONE);
    Stonewt stn3(14, 3.5, Stonewt::POUND_DOUBLE);

    cout << "제1 객체: " << stn1 << "\n";
    cout << "제2 객체: " << stn2 << "\n";
    cout << "제3 객체: " << stn3 << "\n";

    Stonewt result;
    result = stn1 + stn2;
    result.SetMode(Stonewt::STONE);
    cout << "stn1 + stn2 = " << result << "(스톤 파운드 조합 형식)\n";
    result = stn1 - stn2;
    result.SetMode(Stonewt::POUND_INT);
    cout << "stn1 - stn2 = " << result << "(정수 파운드 형식)\n";
    result = stn1 * stn2;
    result.SetMode(Stonewt::POUND_DOUBLE);
    cout << "stn1 * stn2 = " << result << "(부동소수점 파운드 형식)\n";
    cout << "프로그램을 종료합니다.\n";
    return 0;
}