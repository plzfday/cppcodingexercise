#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int MAX = 10000000;

int main()
{
	srand(time(0));
	vector<int> vi0;
	for (int i = 0; i < MAX; ++i)
	{
		vi0.push_back(rand() % MAX);
	}
	vector<int> vi(vi0);
	list<int> li(MAX);
	copy(vi0.begin(), vi0.end(), li.begin());

	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	cout << double(end - start) / CLOCKS_PER_SEC << endl;

	start = clock();
	li.sort();
	end = clock();
	cout << double(end - start) / CLOCKS_PER_SEC << endl;

	start = clock();
	copy(vi0.begin(), vi0.end(), li.begin());
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	cout << double(end - start) / CLOCKS_PER_SEC << endl;
	return 0;
}