#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;
	ifstream file1("1.txt"), file2("2.txt");
	if (file1.is_open() && file2.is_open())
	{
		ofstream fout("Merge.txt");
		if (fout.is_open())
		{
			string str1, str2;
			while (!file1.eof() && !file2.eof())
			{
				getline(file1, str1);
				fout << str1 << " ";
				getline(file2, str2);
				fout << str2 << endl;
			}
			while (!file1.eof())
			{
				getline(file1, str1);
				fout << str1 << endl;
			}
			while (!file2.eof())
			{
				getline(file2, str2);
				fout << str2 << endl;
			}
		}
		else
		{
			cerr << "합치려는 파일이 안 열림. ";
		}
		fout.close();
	}
	else
	{
		cerr << "파일 못 열었음. ";
	}
	cout << "프로그램을 종료합니다.\n";
	file1.close();
	file2.close();
	return 0;
}