#include <cstring>
#include <iostream>
#include "classic1.h"

Cd::Cd(const char * s1, const char * s2, const int n, const double x)
{
	using namespace std;

	int s1Len = strlen(s1);
	performers = new char[s1Len + 1];
	strcpy(performers, s1);

	int s2Len = strlen(s2);
	label = new char[s2Len + 1];
	strcpy(label, s2);

	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	using namespace std;

	int s1Len = strlen(d.performers);
	performers = new char[s1Len + 1];
	strcpy(performers, d.performers);

	int s2Len = strlen(d.label);
	label = new char[s2Len + 1];
	strcpy(label, d.label);

	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	using namespace std;

	const char* anonymous = "익명";
	const char* untitled = "무제";

	int anonLen = strlen(anonymous);
	performers = new char[anonLen + 1];
	strcpy(performers, anonymous);

	int untitledLen = strlen(untitled);
	label = new char[untitledLen + 1];
	strcpy(label, untitled);

	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
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
	if (this == &d)
		return *this;
	
	using namespace std;
	delete[] performers;
	delete[] label;

	int s1Len = strlen(d.performers);
	performers = new char[s1Len + 1];
	strcpy(performers, d.performers);

	int s2Len = strlen(d.label);
	label = new char[s2Len + 1];
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
	candidate = new char[len + 1];
	strcpy(candidate, cand);
}

Classic::Classic()
	: Cd()
{
	const char* anonymous = "무제";
	int len = std::strlen(anonymous);
	candidate = new char[len + 1];
	std::strcpy(candidate, anonymous);
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "대표곡: " << candidate << std::endl << std::endl;
}

Classic & Classic::operator=(const Classic & src)
{
	Cd::operator=(src);

	delete[] candidate;
	int len = std::strlen(src.candidate);
	candidate = new char[len + 1];
	std::strcpy(candidate, src.candidate);

	return *this;
}
