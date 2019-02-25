#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cout << "Mat�� ģ������ �� ���ΰ���?\n";
	unsigned matFriendsCount;
	(cin >> matFriendsCount).get();

	vector<string> friendsOfMat;
	string tempInput;
	int i;
	for (i = 0; i < matFriendsCount; ++i)
	{
		cout << i + 1 << ": ";
		getline(cin, tempInput);
		friendsOfMat.push_back(tempInput);
	}
	sort(friendsOfMat.begin(), friendsOfMat.end());

	cout << "Pat�� ģ������ �� ���ΰ���?\n";
	unsigned patFriendsCount;
	(cin >> patFriendsCount).get();

	vector<string> friendsOfPat;
	for (i = 0; i < patFriendsCount; ++i)
	{
		cout << i + 1 << ": ";
		getline(cin, tempInput);
		friendsOfPat.push_back(tempInput);
	}
	sort(friendsOfPat.begin(), friendsOfPat.end());

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
		cout << i << ' ';
	}
	return 0;
}