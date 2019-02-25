#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template<class T>
int reduce(T ar[], int n);

template<class T>
void show(T ar[], int n);

int main()
{
	long arrl[]{ 10, 300, 5, 2, 4, 3, 2, 1, 1 };
	string arrs[]{ "abc", "chocolate", "clock", "sort", "clock", "beesaa", "abc" };
	int ns = reduce(arrl, 9);
	int nw = reduce(arrs, 7);
	show(arrl, ns);
	cout << endl;
	show(arrs, nw);
	return 0;
}

template<class T>
int reduce(T ar[], int n)
{
	sort(ar, ar + n);
	T* add = unique(ar, ar + n);
	return add - ar;
}

template<class T>
void show(T ar[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << ar[i] << ' ';
	}
}