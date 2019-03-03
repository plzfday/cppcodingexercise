#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	using namespace std;
	if (argc == 1)
	{
		cerr << "� ���Ͽ� �����ؾ��ұ��? �������ּ���!\n";
		exit(EXIT_FAILURE);
	}
	ifstream fin(argv[1]);
	if (fin.is_open())
	{
		ofstream fout("copy.txt");
		if (fout.is_open())
		{
			string str;
			while (getline(fin, str))
			{
				fout << str << endl;
			}
		}
		else
		{
			cerr << "�ٿ��ֱ� �Ϸ��� ������ ���� �������� ������ �߻��߽��ϴ�. ";
		}
		fout.close();
	}
	else
	{
		cerr << "������ ���� �������� ������ �߻��߽��ϴ�. ";
	}
	fin.close();
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}