#ifndef BADDUDE_HPP_
#define BADDUDE_HPP_

#include "gunslinger.hpp"
#include "pokerplayer.hpp"

class BadDude : public Gunslinger, public PokerPlayer
{
public:
	BadDude();
	BadDude(const std::string& firstName, const std::string& lastName, int notch, double drawtime);
	BadDude(const Person& person, int notch, double drawtime);
	virtual ~BadDude() {}
	double Gdraw() const { Gunslinger::GetDrawTime(); }
	int Cdraw() const { return PokerPlayer::GetDraw(); }
	void DoShow() const override;
	void DoSet() override;
};

#endif // !BADDUDE_HPP_
