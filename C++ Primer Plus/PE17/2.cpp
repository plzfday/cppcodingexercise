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
	ofstream fout(argv[1]);
	if (fout.is_open())
	{
		string str;
		while (getline(cin, str))
		{
			fout << str << endl;
		}
		fout.clear();
		fout.close();
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}