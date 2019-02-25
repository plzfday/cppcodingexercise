#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

vector<int> Lotto(int num, unsigned int digits);

int main()
{
	srand(time(0));
	vector<int> winners = Lotto(51, 6);
	for (auto& i : winners)
	{
		cout << i << ' ';
	}
	return 0;
}

vector<int> Lotto(int num, unsigned int digits)
{
	vector<int> numbers;
	for (int i = 1; i <= num; ++i)
	{
		numbers.push_back(i);
	}
	random_shuffle(numbers.begin(), numbers.end());
	return vector<int>(numbers.begin(), numbers.begin() + digits);
}
