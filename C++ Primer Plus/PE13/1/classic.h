#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(const char* s1, const char* s2, const int n, const double x);
	Cd(const Cd& d);
	Cd();
	~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& d);
};

class Classic : public Cd
{
private:
	char candidate[100];
public:
	Classic(const char* cand, const char* s1, const char* s2, int n, double x);
	Classic();
	virtual void Report() const;
	Classic& operator=(const Classic& src);
};

#endif // !CLASSIC_H_
