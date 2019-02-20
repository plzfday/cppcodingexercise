#ifndef WINEI_H_
#define WINEI_H_

#include <iostream>
#include <string>
#include <valarray>
#include "pairs.h"

class Wine : private std::string,
			 private Pair<std::valarray<int>, std::valarray<int>>
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	int years;
public:
	Wine() : std::string("none"), years(0), PairArray(ArrayInt(), ArrayInt()) {}
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, const ArrayInt& yr, const ArrayInt& bot);
	Wine(const char* l, const PairArray& yr_bot);
	Wine(const char* l, int y);
	void GetBottles();
	void Show() const;
	const std::string& Label() const { return (const std::string&)(*this); }
	int sum() const { return PairArray::second().sum(); }
};

#endif // !WINEI_H_
