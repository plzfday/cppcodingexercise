#ifndef WINEC_H_
#define WINEC_H_

#include <iostream>
#include <string>
#include <valarray>
#include "pairs.h"

class Wine
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	std::string mName;
	int years;
	PairArray mInfo;
public:
	Wine() : mName("none"), years(0), mInfo(ArrayInt(), ArrayInt()) {}
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, const ArrayInt& yr, const ArrayInt& bot);
	Wine(const char* l, const PairArray& yr_bot);
	Wine(const char* l, int y);
	void GetBottles();
	void Show() const;
	const std::string& Label() const { return mName; }
	int sum() const { return mInfo.second().sum(); }
};

#endif // !WINEC_H_
