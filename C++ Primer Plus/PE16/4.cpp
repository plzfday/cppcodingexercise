#include <iostream>
#include <algorithm>

int reduce(long ar[], int n);
void show(long ar[], int n);

int main()
{
	long arr[]{ 10, 300, 5, 2, 4, 3, 2, 1, 1 };
	int ns = reduce(arr, 8);
	show(arr, ns);
	return 0;
}

int reduce(long ar[], int n)
{
	std::sort(ar, ar + n);
	long* add = std::unique(ar, ar + n);
	return add - ar;
}

void show(long ar[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << ar[i] << ' ';
	}
}