#include <cstring>
#include <iostream>
#include "classic.h"

Cd::Cd(const char * s1, const char * s2, const int n, const double x)
{
	using namespace std;
	int s1Len = strlen(s1);
	int s2Len = strlen(s2);

	strncpy(performers, s1, 49);
	performers[49] = '\0';
	strncpy(label, s2, 19);
	label[19] = '\0';
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	strcpy(performers, "익명");
	strcpy(label, "무제");
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
}

void Cd::Report() const
{
	std::cout << "가수: " << performers 
		      << "\n라벨: " << label 
		      << "\n수록곡 개수: " << selections 
		      << "\n연주 시간(분): " << playtime << std::endl << std::endl;
}

Cd & Cd::operator=(const Cd & d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}

Classic::Classic(const char * cand, const char * s1, const char * s2, int n, double x)
	: Cd(s1, s2, n, x)
{
	using namespace std;
	int len = strlen(cand);
	strncpy(candidate, cand, 99);
	candidate[99] = '\0';
}

Classic::Classic()
	: Cd()
{
	std::strcpy(candidate, "무제");
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "대표곡: " << candidate << std::endl << std::endl;
}

Classic & Classic::operator=(const Classic & src)
{
	Cd::operator=(src);
	std::strcpy(candidate, src.candidate);

	return *this;
}
