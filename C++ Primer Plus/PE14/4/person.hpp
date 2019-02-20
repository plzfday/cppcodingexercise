#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>
#include <iostream>

class Person
{
private:
	std::string mFirstName;
	std::string mLastName;
public:
	Person();
	Person(const std::string& firstName, const std::string& lastName);
	virtual ~Person();
	virtual void DoShow() const;
	virtual void DoSet();
};

#endif // !PERSON_HPP_
