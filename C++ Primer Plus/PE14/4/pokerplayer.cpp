#include "pokerplayer.hpp"

PokerPlayer::PokerPlayer()
	: Person("Pokey", "Dekey")
{
}

PokerPlayer::PokerPlayer(const std::string & firstName, const std::string & lastName)
	: Person(firstName, lastName)
{
}

PokerPlayer::PokerPlayer(const Person & person)
	: Person(person)
{
}

int PokerPlayer::GetDraw() const
{
	return std::rand() % 52 + 1;
}
