#include "emp.h"
using namespace std;

void employee::ShowAll() const
{
	cout << "�۽�Ʈ �̸�: " << fname << "\n";
	cout << "���Ʈ �̸�: " << lname << "\n";
	cout << "����� ����: " << job << "\n";
}

void employee::SetAll()
{
	cout << "�۽�Ʈ �̸��� �Է��Ͻʽÿ�: ";
	cin >> fname;
	cout << "��Ʈ �̸��� �Է��Ͻʽÿ�: ";
	cin >> lname;
	cout << "����� ������ �Է��Ͻʽÿ�: ";
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
	cout << "manager �����Դϴ�.\n";
	employee::ShowAll();
	cout << "inchargeof: " << inchargeof << '\n';
}

void manager::SetAll()
{
	cout << "manager ������ �Է��Ͻʽÿ�.\n";
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
	cout << "fink �����Դϴ�.\n";
	employee::ShowAll();
	cout << "reportsto: " << reportsto << '\n';
}

void fink::SetAll()
{
	cout << "fink ������ �Է��Ͻʽÿ�.\n";
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
	cout << "highfink �����Դϴ�.\n";
	employee::ShowAll();
	cout << "inchargeof: " << inchargeof << '\n';
	cout << "reportsto: " << reportsto << '\n';;
}

void highfink::SetAll()
{
	cout << "fink ������ �Է��Ͻʽÿ�.\n";
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