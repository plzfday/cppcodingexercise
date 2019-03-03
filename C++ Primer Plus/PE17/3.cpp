#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	using namespace std;
	if (argc == 1)
	{
		cerr << "어떤 파일에 저장해야할까요? 지정해주세요!\n";
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
			cerr << "붙여넣기 하려는 파일을 여는 과정에서 문제가 발생했습니다. ";
		}
		fout.close();
	}
	else
	{
		cerr << "파일을 여는 과정에서 문제가 발생했습니다. ";
	}
	fin.close();
	cout << "프로그램을 종료합니다.\n";
	return 0;
}