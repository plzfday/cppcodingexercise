#include "port.h"

Port::Port(const char * br, const char * st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);

	if (strlen(st) >= 20)
		cerr << "Max length of string is 19.\n";
	strncpy(style, st, 19);
	style[19] = '\0';
	if (b < 0)
	{
		bottles = 0;
	}
	else
	{
		bottles = b;
	}
}

Port::Port(const Port & p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
	if (this == &p)
		return *this;
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port & Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b)
{
	if (bottles < b)
	{
		cerr << "Bottle ������ ��� �� �̻� �� �� �����ϴ�.\n0���� �����մϴ�.";
		bottles = 0;
	}
	else
	{
		bottles -= b;
	}
	return *this;
}

void Port::Show() const
{
	cout << "�귣��: " << brand
		 << "\n��Ÿ��: " << style
		 << "\n����: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
	os << (Port &)vp;
	if (vp.nickname == nullptr)
	{
		os << ", " << vp.year;
	}
	else
	{
		os << ", " << vp.nickname << ", " << vp.year;
	}
	return os;
}

VintagePort::VintagePort()
	: Port()
{
	nickname = nullptr;
	year = 1900;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
	: Port(br, "Vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
	: Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete[] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

void VintagePort::Show() const
{
	Port::Show();
	if (nickname == nullptr)
	{
		cout << "���� ��Ȯ �⵵: " << year << endl;
	}
	else
	{
		cout << "����: " << nickname
		     << "\n���� ��Ȯ �⵵: " << year << endl;
	}
}
