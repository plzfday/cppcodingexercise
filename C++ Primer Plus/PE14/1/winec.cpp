#include "winec.h"

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
	: mName(l), mInfo(ArrayInt(yr, y), ArrayInt(bot, y))
{
}

Wine::Wine(const char * l, const ArrayInt & yr, const ArrayInt & bot)
	: mName(l), years(yr.size()), mInfo(ArrayInt(yr), ArrayInt(bot))
{
	if (yr.size() != bot.size())
	{
		std::cerr << "수확 년도 데이터와 와인 수량 데이터가 맞지 않습니다. 전부 0으로 세팅합니다.\n";
		years = 0;
		mInfo = PairArray(ArrayInt(), ArrayInt());
	}
	else
	{
		mInfo.first() = yr;
		mInfo.second() = bot;
	}
}

Wine::Wine(const char * l, const PairArray & yr_bot)
	: mName(l), years(yr_bot.first().size()), mInfo(yr_bot) 
{
}

Wine::Wine(const char * l, int y)
	: mName(l), years(y), mInfo(ArrayInt(0, y), ArrayInt(0, y))
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

	cout << years << "년 간의 " << mName << " 데이터를 입력하시오:\n";
	for (int i = 0; i < years; ++i)
	{
		cout << "년도를 입력하시오: ";
		cin >> mInfo.first()[i];
		cout << "수량을 입력하시오: ";
		cin >> mInfo.second()[i];
	}
}

void Wine::Show() const
{
	std::cout << "와인: " << mName << "\n\t년도\t수량\n";
	for (int i = 0; i < years; ++i)
	{
		std::cout << "\t" << mInfo.first()[i] << "\t" << mInfo.second()[i] << std::endl;
	}
}
