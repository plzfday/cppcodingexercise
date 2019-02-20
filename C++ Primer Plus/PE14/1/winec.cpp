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
		std::cerr << "��Ȯ �⵵ �����Ϳ� ���� ���� �����Ͱ� ���� �ʽ��ϴ�. ���� 0���� �����մϴ�.\n";
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
		cout << "������ �� ����\n";
		return;
	}

	cout << years << "�� ���� " << mName << " �����͸� �Է��Ͻÿ�:\n";
	for (int i = 0; i < years; ++i)
	{
		cout << "�⵵�� �Է��Ͻÿ�: ";
		cin >> mInfo.first()[i];
		cout << "������ �Է��Ͻÿ�: ";
		cin >> mInfo.second()[i];
	}
}

void Wine::Show() const
{
	std::cout << "����: " << mName << "\n\t�⵵\t����\n";
	for (int i = 0; i < years; ++i)
	{
		std::cout << "\t" << mInfo.first()[i] << "\t" << mInfo.second()[i] << std::endl;
	}
}
