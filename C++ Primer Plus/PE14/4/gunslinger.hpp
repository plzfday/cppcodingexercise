#ifndef GUNSLINGER_HPP_
#define GUNSLINGER_HPP_

#include "person.hpp"

class Gunslinger : virtual public Person
{
private:
	int mNotch;
	double mDrawTime;
public:
	Gunslinger();
	Gunslinger(const std::string& firstName, const std::string& lastName, int notch, double drawtime);
	Gunslinger(const Person& person, int notch, double drawtime);
	double GetDrawTime() const { return mDrawTime; }
	virtual void DoShow() const override;
	virtual void DoSet() override;
};

#endif // !GUNSLINGER_HPP_
