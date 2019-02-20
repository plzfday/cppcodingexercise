#include "emp.h"

void abstr_emp::ShowAll() const
{
	std::cout << "Name: " << fname << " " << lname << ", Job: " << job << std::endl;
}

void abstr_emp::SetAll()
{
	using std::cout;
	using std::cin;
	using std::getline;
	cout << "first name: ";
	getline(cin, fname);
	cout << "last name: ";
	getline(cin, lname);
	cout << "job: ";
	getline(cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	os << "Name: " << e.fname << " " << e.lname << ", Job: " << e.job << std::endl;
	return os;
}

void manager::ShowAll() const
{
	std::cout << "Manager:\n";
	abstr_emp::ShowAll();
	std::cout << "Counts of 'abstr_emp': " << inchargeof << std::endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Input counts of managing abstr_emps: ";
	std::cin >> inchargeof;
}

void fink::ShowAll() const
{
	std::cout << "Fink\n";
	abstr_emp::ShowAll();
	std::cout << "Report to " << reportsto << std::endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Reports to who?: ";
	std::getline(std::cin, reportsto);
}

void highfink::ShowAll() const
{
	std::cout << "High Fink\n";
	abstr_emp::ShowAll();
	std::cout << "Counts of 'abstr_emp': " << InChargeOf() << std::endl;
	std::cout << "Report to " << ReportsTo() << std::endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Input counts of managing abstr_emps: ";
	(std::cin >> InChargeOf()).get();
	std::cout << "Reports to who?: ";
	std::getline(std::cin, ReportsTo());
}
