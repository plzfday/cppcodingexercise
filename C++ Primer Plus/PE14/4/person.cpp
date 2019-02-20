#include "person.hpp"

Person::Person()
	: mFirstName(), mLastName()
{
}

Person::Person(const std::string & firstName, const std::string & lastName)
	: mFirstName(firstName), mLastName(lastName)
{
}

Person::~Person()
{
}

void Person::DoShow() const
{
	std::cout << mFirstName << " " << mLastName << std::endl;
}

void Person::DoSet()
{
	std::cout << "¼º: ";
	std::getline(std::cin, mLastName);
	std::cout << "ÀÌ¸§: ";
	std::getline(std::cin, mFirstName);
}