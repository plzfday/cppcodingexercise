// exc_mean.h  -- hmean(), gmean()을 위한 예외 클래스
#include <iostream>
#include <string>

class BaseBad
{
protected:
	double first;
	double second;
public:
	BaseBad(double f, double s) : first(f), second(s) { }
	virtual void what() const
	{
		std::cout << "Error Occured[BaseBad]: " << first << ", " << second << std::endl;
	}
};

class bad_hmean : public BaseBad
{
public:
    bad_hmean(double f, double s)
		: BaseBad(f, s) {}
	void what() const
	{
		std::cout << "Error Occured[bad_hmean]: " << first << ", " << second << std::endl;
	}
};

class bad_gmean : public BaseBad
{
public:
    bad_gmean(double f, double s)
		: BaseBad(f, s) {}
	void what() const
	{
		std::cout << "Error Occured[bad_gmean]: " << first << ", " << second << std::endl;
	}
};
