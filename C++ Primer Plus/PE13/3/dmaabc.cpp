#include <cstring>
#include "dmaabc.h"

void dmaABC::print(std::ostream & os) const
{
	os << "상표: " << label << std::endl;
	os << "등급: " << rating << std::endl;
}

dmaABC::dmaABC(const char * l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

dmaABC::dmaABC(const dmaABC & rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}

dmaABC::~dmaABC()
{
	delete[] label;
}

void dmaABC::View() const
{
	std::cout << "상표: " << label << std::endl;
	std::cout << "등급: " << rating << std::endl;
}

dmaABC & dmaABC::operator=(const dmaABC & rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const dmaABC & rs)
{
	rs.print(os);
	return os;
}

void baseDMA::print(std::ostream & os) const
{
	dmaABC::print(os);
}

baseDMA::baseDMA(const char * l, int r)
	: dmaABC(l, r)
{
}

baseDMA::baseDMA(const baseDMA & rs)
	: dmaABC(rs)
{
}

baseDMA::~baseDMA()
{
}

void baseDMA::View() const
{
	dmaABC::View();
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if (this == &rs)
		return *this;
	dmaABC::operator=(rs);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	rs.print(os);
	return os;
}

void lacksDMA::print(std::ostream & os) const
{
	dmaABC::print(os);
	os << "색상: " << color << std::endl;
}

lacksDMA::lacksDMA(const char * c, const char * l, int r)
	: dmaABC(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
	: dmaABC(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const
{
	dmaABC::View();
	std::cout << "색상: " << color << std::endl;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & rs)
{
	rs.print(os);
	return os;
}

void hasDMA::print(std::ostream & os) const
{
	dmaABC::print(os);
	std::cout << "스타일: " << style << std::endl;
}

hasDMA::hasDMA(const char * s, const char * l, int r)
	: dmaABC(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs)
	: dmaABC(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
	: dmaABC(hs)
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

void hasDMA::View() const
{
	dmaABC::View();
	std::cout << "스타일: " << style << std::endl;
}

hasDMA & hasDMA::operator=(const hasDMA & rs)
{
	if (this == &rs)
		return *this;
	dmaABC::operator=(rs);
	delete[] style;
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & rs)
{
	rs.print(os);
	return os;
}