#ifndef POKERPLAYER_HPP_
#define POKERPLAYER_HPP_

#include <cstdlib>
#include "person.hpp"

class PokerPlayer : virtual public Person
{
public:
	PokerPlayer();
	PokerPlayer(const std::string& firstName, const std::string& lastName);
	PokerPlayer(const Person& person);
	virtual ~PokerPlayer() {}
	int GetDraw() const;
};

#endif // !POKERPLAYER_HPP_
