#include "winei.h"

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
	: std::string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{
}

Wine::Wine(const char * l, const ArrayInt & yr, const ArrayInt & bot)
	: std::string(l), years(yr.size()), PairArray(ArrayInt(yr), ArrayInt(bot))
{
	if (yr.size() != bot.size())
	{
		std::cerr << "수확 년도 데이터와 와인 수량 데이터가 맞지 않습니다. 전부 0으로 세팅합니다.\n";
		years = 0;
		PairArray::operator=(PairArray(ArrayInt(), ArrayInt()));
	}
	else
	{
		PairArray::first() = yr;
		PairArray::second() = bot;
	}
}

Wine::Wine(const char * l, const PairArray & yr_bot)
	: std::string(l), years(yr_bot.first().size()), PairArray(yr_bot)
{
}

Wine::Wine(const char * l, int y)
	: std::string(l), years(y), PairArray(ArrayInt(0, y), ArrayInt(0, y))
{
}

void Wine::GetBottles()
{
	using std::cout;
	using std::cin;

	if (years < 1)
	{
		cout << "저장할 게 없음\n";
		return;
	}

	cout << years << "년 간의 " << Label() << " 데이터를 입력하시오:\n";
	for (int i = 0; i < years; ++i)
	{
		cout << "년도를 입력하시오: ";
		cin >> PairArray::first()[i];
		cout << "수량을 입력하시오: ";
		cin >> PairArray::second()[i];
	}
}

void Wine::Show() const
{
	std::cout << "와인: " << Label() << "\n\t년도\t수량\n";
	for (int i = 0; i < years; ++i)
	{
		std::cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << std::endl;
	}
}
