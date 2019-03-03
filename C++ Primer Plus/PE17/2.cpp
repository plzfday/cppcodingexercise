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
	cout << "프로그램을 종료합니다.\n";
	return 0;
}