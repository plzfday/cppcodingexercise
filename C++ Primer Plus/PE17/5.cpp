#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("mat.dat");
	if (!fin.is_open())
	{
		cerr << "�� ����.\n";
		exit(EXIT_FAILURE);
	}
	string tempInput;
	int i;

	vector<string> friendsOfMat;
	while (getline(fin, tempInput))
	{
		friendsOfMat.push_back(tempInput);
	}
	sort(friendsOfMat.begin(), friendsOfMat.end());
	fin.close();

	fin.open("pat.dat");
	if (!fin.is_open())
	{
		cerr << "�� ����.\n";
		exit(EXIT_FAILURE);
	}
	vector<string> friendsOfPat;
	while (getline(fin, tempInput))
	{
		friendsOfPat.push_back(tempInput);
	}
	sort(friendsOfPat.begin(), friendsOfPat.end());
	fin.clear();
	fin.close();

	ofstream fout("matnpat.dat");
	if (!fout.is_open())
	{
		cerr << "�� ����.\n";
		exit(EXIT_FAILURE);
	}
	vector<string> mergeThemUp = friendsOfMat;
	mergeThemUp.insert(mergeThemUp.end(), friendsOfPat.begin(), friendsOfPat.end());

	sort(mergeThemUp.begin(), mergeThemUp.end());
	auto it = unique(mergeThemUp.begin(), mergeThemUp.end());
	mergeThemUp.erase(it, mergeThemUp.end());

	cout << "Mat�� ģ����\n";
	for (auto& i : friendsOfMat)
	{
		cout << i << ' ';
	}
	cout << "\nPat�� ģ����\n";
	for (auto& i : friendsOfPat)
	{
		cout << i << ' ';
	}
	cout << "\nMat�� Pat�� ģ����\n";
	for (auto& i : mergeThemUp)
	{
		fout << i << endl;
	}
	fout.close();
	return 0;
}