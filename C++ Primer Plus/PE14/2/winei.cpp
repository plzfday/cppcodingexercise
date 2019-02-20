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
		std::cerr << "��Ȯ �⵵ �����Ϳ� ���� ���� �����Ͱ� ���� �ʽ��ϴ�. ���� 0���� �����մϴ�.\n";
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
		cout << "������ �� ����\n";
		return;
	}

	cout << years << "�� ���� " << Label() << " �����͸� �Է��Ͻÿ�:\n";
	for (int i = 0; i < years; ++i)
	{
		cout << "�⵵�� �Է��Ͻÿ�: ";
		cin >> PairArray::first()[i];
		cout << "������ �Է��Ͻÿ�: ";
		cin >> PairArray::second()[i];
	}
}

void Wine::Show() const
{
	std::cout << "����: " << Label() << "\n\t�⵵\t����\n";
	for (int i = 0; i < years; ++i)
	{
		std::cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << std::endl;
	}
}
