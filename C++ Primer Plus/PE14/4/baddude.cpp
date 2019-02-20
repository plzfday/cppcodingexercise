#include "baddude.hpp"

BadDude::BadDude()
{
}

BadDude::BadDude(const std::string & firstName, const std::string & lastName, int notch, double drawtime)
	: Person(firstName, lastName), Gunslinger(firstName, lastName, notch, drawtime), PokerPlayer(firstName, lastName)
{
}

BadDude::BadDude(const Person & person, int notch, double drawtime)
	: Person(person), Gunslinger(person, notch, drawtime), PokerPlayer(person)
{
}

void BadDude::DoShow() const
{
	Gunslinger::DoShow();
}

void BadDude::DoSet()
{
	Gunslinger::DoSet();
}
