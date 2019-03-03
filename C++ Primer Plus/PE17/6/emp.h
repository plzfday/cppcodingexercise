#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <fstream>
#include <string>

enum classkind { Employee = 1, Manager, Fink, Highfink };

class employee
{
public:
	std::string fname;
	std::string lname;
	std::string job;
public:
	employee() {}
	employee(const std::string& fn, const std::string& ln, const std::string& j)
		: fname(fn), lname(ln), job(j) {}
	employee(const employee& e)
		: fname(e.fname), lname(e.lname), job(e.job) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(std::ofstream & fout, int classtype);
	virtual void GetAll(std::ifstream& fin);
	friend std::ostream& operator<< (std::ostream& os, const employee& e);
};

class manager : virtual public employee
{
protected:
	int inchargeof;
public:
	manager()
		: employee(), inchargeof(0) {}
	manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0)
		: employee(fn, ln, j), inchargeof(ico) {}
	manager(const employee& e, int ico)
		: employee(e), inchargeof(ico) {}
	manager(const manager& m)
		: employee(m), inchargeof(m.inchargeof) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(std::ofstream & fout, int classtype);
	virtual void GetAll(std::ifstream& fin);
};

class fink : virtual public employee
{
protected:
	std::string reportsto;
public:
	fink() { }
	fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
		: employee(fn, ln, j), reportsto(rpo) {}
	fink(const employee& e, const std::string& rpo)
		: employee(e), reportsto(rpo) {}
	fink(const fink& e)
		: employee(e), reportsto(e.reportsto) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(std::ofstream & fout, int classtype);
	virtual void GetAll(std::ifstream& fin);
};

class highfink : public manager, public fink
{
public:
	highfink() { }
	highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico)
		: employee(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
	highfink(const employee& e, const std::string& rpo, int ico)
		: employee(e), manager(e, ico), fink(e, rpo) {}
	highfink(const fink& f, int ico)
		: employee(f), manager(f, ico), fink(f) {}
	highfink(const manager& m, const std::string& rpo)
		: employee(m), manager(m), fink(m, rpo) {}
	highfink(const highfink& h) { }
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(std::ofstream & fout, int classtype);
	virtual void GetAll(std::ifstream& fin);
};

#endif // !EMP_H_
