// pe13-03.cpp -- 추상화 기초 클래스를 설명하는 예제
// dmaabc.cpp와 함께 컴파일한다
#include <iostream>
using namespace std;
#include "dmaabc.h"
const int GOODS = 4;
const int LEN = 40;
const int COLORS = 20;
const int STYLES = 20;

int main()
{
	dmaABC * p_goods[GOODS];

	int i;
	for (i = 0; i < GOODS; i++)
	{
		char tlabel[LEN];
		int trating;
		char tcolor[COLORS];
		char tstyle[STYLES];
		char kind;

		cout << "상표를 입력하십시오: ";
		cin.getline(tlabel, LEN);
		cout << "등급을 입력하십시오: ";
		cin >> trating;
		cout << "baseDMA 객체는 1, "
			<< "lacksDMA 객체는 2, hasDMA 객체는 3을 입력하십시오: ";
		while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
			cout << "1, 2, 3 중에서 하나를 입력하십시오: ";
		while (cin.get() != '\n')
			continue;
		if (kind == '1')
		{
			p_goods[i] = new baseDMA(tlabel, trating);
		}
		else if (kind == '2')
		{
			cout << "색상을 입력하십시오: ";
			cin.getline(tcolor, COLORS);
			p_goods[i] = new lacksDMA(tcolor, tlabel, trating);
		}
		else
		{
			cout << "스타일을 입력하십시오: ";
			cin.getline(tstyle, STYLES);
			p_goods[i] = new hasDMA(tstyle, tlabel, trating);
		}
	}
	cout << endl;
	for (i = 0; i < GOODS; i++)
	{
		cout << *p_goods[i];
		//p_goods[i]->View();
		cout << endl;
	}

	for (i = 0; i < GOODS; i++)
	{
		delete p_goods[i];	// 메모리를 해제한다
	}
	cout << "프로그램을 종료합니다.\n";

	return 0;
}
