#include <string>
#include <iostream>
using namespace std;

class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info* pi;
public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv& cp);
	Cpmv(Cpmv&& mv);
	~Cpmv();
	Cpmv& operator=(const Cpmv& cp);
	Cpmv& operator=(Cpmv&& mv);
	Cpmv operator+(const Cpmv& obj) const;
	void Display() const;
};

int main()
{
	Cpmv one("q1", "z1");
	std::cout << "one -> "; one.Display();
	Cpmv two("q2", "z2");
	std::cout << "two -> "; two.Display();
	std::cout << "--------------------------------------" << std::endl;
	Cpmv three(Cpmv("q3", "z3"));
	std::cout << "three -> "; three.Display();
	std::cout << "--------------------------------------" << std::endl;
	Cpmv four;
	four = one + two + three;
	std::cout << "four -> "; four.Display();
	return 0;
}

Cpmv::Cpmv()
	: pi(nullptr)
{
}

Cpmv::Cpmv(std::string q, std::string z)
	: pi(new Info{ q, z })
{
}

Cpmv::Cpmv(const Cpmv & cp)
	: pi(new Info{ cp.pi->qcode, cp.pi->zcode })
{
}

Cpmv::Cpmv(Cpmv && mv)
{
	pi = mv.pi;
	mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
	delete pi;
	pi = nullptr;
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
	if (this == &cp)
		return *this;
	delete pi;
	pi = new Info{ cp.pi->qcode, cp.pi->zcode };
	return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
	if (this == &mv)
		return *this;
	delete pi;
	pi = mv.pi;
	mv.pi = nullptr;
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
	return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
}

void Cpmv::Display() const
{
	cout << "Qcode: " << pi->qcode << '\n';
	cout << "Zcode: " << pi->zcode << '\n';
}
