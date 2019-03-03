#include "emp.h"
using namespace std;

void employee::ShowAll() const
{
	cout << "퍼스트 이름: " << fname << "\n";
	cout << "라시트 이름: " << lname << "\n";
	cout << "사원의 직무: " << job << "\n";
}

void employee::SetAll()
{
	cout << "퍼스트 이름을 입력하십시오: ";
	cin >> fname;
	cout << "라스트 이름을 입력하십시오: ";
	cin >> lname;
	cout << "사원의 직무를 입력하십시오: ";
	cin >> job;
}

void employee::WriteAll(std::ofstream & fout, int classtype)
{
	fout << classtype << '\n';
	fout << fname << '\n';
	fout << lname << '\n';
	fout << job << '\n';
}

void employee::GetAll(std::ifstream & fin)
{
	char ch;

	cout << "\nfname: ";

	fin.get(ch);
	while (fin.get(ch)) {
		if (ch == '\n') {
			break;
		}
		else {
			cout << ch;
		}
	}

	cout << "\nlname: ";
	while (fin.get(ch)) {
		if (ch == '\n') {
			break;
		}
		else {
			cout << ch;
		}
	}

	cout << "\njob: ";
	while (fin.get(ch)) {
		if (ch == '\n') {
			break;
		}
		else {
			cout << ch;
		}
	}
}

std::ostream & operator<<(std::ostream & os, const employee & e)
{
	os << e.fname << "\n";
	os << e.lname << "\n";
	os << e.job << "\n";

	return os;
}

void manager::ShowAll() const
{
	cout << "manager 정보입니다.\n";
	employee::ShowAll();
	cout << "inchargeof: " << inchargeof << '\n';
}

void manager::SetAll()
{
	cout << "manager 정보를 입력하십시오.\n";
	employee::SetAll();
	cout << "inchargeof: ";
	cin >> inchargeof;
}

void manager::WriteAll(std::ofstream & fout, int classtype)
{
	employee::WriteAll(fout, classtype);
	fout << inchargeof << '\n';
}

void manager::GetAll(std::ifstream & fin)
{
	char ch;

	employee::GetAll(fin);
	cout << "\ninchargeof: ";
	while (fin.get(ch)) {
		if (ch == '\n') {
			break;
		}
		else {
			cout << ch;
		}
	}
}

void fink::ShowAll() const
{
	cout << "fink 정보입니다.\n";
	employee::ShowAll();
	cout << "reportsto: " << reportsto << '\n';
}

void fink::SetAll()
{
	cout << "fink 정보를 입력하십시오.\n";
	employee::SetAll();
	cout << "reportsto: ";
	cin >> reportsto;
}

void fink::WriteAll(ofstream & fout, int classtype)
{
	employee::WriteAll(fout, classtype);
	fout << reportsto << '\n';
}

void fink::GetAll(ifstream & fin)
{
	char ch;

	employee::GetAll(fin);
	cout << "\nreportsto: ";
	while (fin.get(ch)) {
		if (ch == '\n') {
			break;
		}
		else {
			cout << ch;
		}
	}
}

void highfink::ShowAll() const
{
	cout << "highfink 정보입니다.\n";
	employee::ShowAll();
	cout << "inchargeof: " << inchargeof << '\n';
	cout << "reportsto: " << reportsto << '\n';;
}

void highfink::SetAll()
{
	cout << "fink 정보를 입력하십시오.\n";
	manager::SetAll();
	cout << "reportsto: ";
	cin >> reportsto;
}

void highfink::WriteAll(ofstream & fout, int classtype)
{
	manager::WriteAll(fout, classtype);
	fout << reportsto << '\n';
}

void highfink::GetAll(ifstream & fin)
{
	char ch;

	manager::GetAll(fin);
	cout << "\nreportsto: ";
	while (fin.get(ch)) {
		if (ch == '\n') {
			break;
		}
		else {
			cout << ch;
		}
	}
}