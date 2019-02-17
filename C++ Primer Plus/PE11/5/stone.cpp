#include <iostream>
#include "stonewt.h"

using std::cout;

int main()
{
    Stonewt stn1(99.2);
    Stonewt stn2(30.9, Stonewt::STONE);
    Stonewt stn3(14, 3.5, Stonewt::POUND_DOUBLE);

    cout << "��1 ��ü: " << stn1 << "\n";
    cout << "��2 ��ü: " << stn2 << "\n";
    cout << "��3 ��ü: " << stn3 << "\n";

    Stonewt result;
    result = stn1 + stn2;
    result.SetMode(Stonewt::STONE);
    cout << "stn1 + stn2 = " << result << "(���� �Ŀ�� ���� ����)\n";
    result = stn1 - stn2;
    result.SetMode(Stonewt::POUND_INT);
    cout << "stn1 - stn2 = " << result << "(���� �Ŀ�� ����)\n";
    result = stn1 * stn2;
    result.SetMode(Stonewt::POUND_DOUBLE);
    cout << "stn1 * stn2 = " << result << "(�ε��Ҽ��� �Ŀ�� ����)\n";
    cout << "���α׷��� �����մϴ�.\n";
    return 0;
}