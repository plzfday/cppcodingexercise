#include "gunslinger.hpp"

Gunslinger::Gunslinger()
	: Person("Gunslinger", "Nitche"), mNotch(0), mDrawTime(0.0)
{
}

Gunslinger::Gunslinger(const std::string & firstName, const std::string & lastName, int notch, double drawtime)
	: Person(firstName, lastName), mNotch(notch), mDrawTime(drawtime)
{
}

Gunslinger::Gunslinger(const Person & person, int notch, double drawtime)
	: Person(person), mNotch(notch), mDrawTime(drawtime)
{
}

void Gunslinger::DoShow() const
{
	Person::DoShow();
	std::cout << "금 수: " << mNotch << ", 빼내는 데 걸리는 시간: " << mDrawTime << std::endl;
}

void Gunslinger::DoSet()
{
	Person::DoSet();
	std::cout << "금 수: ";
	std::cin >> mNotch;
	std::cout << "빼내는 데 걸리는 시간: ";
	std::cin >> mDrawTime;
}
