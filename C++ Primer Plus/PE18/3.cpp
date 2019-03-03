#include <iostream>
using namespace std;

template<typename T>
long double sum_values(const T& value)
{
	return static_cast<long double>(value);
}

template<typename T, typename... Args>
long double sum_values(const T& value, const Args&... args)
{
	return sum_values(value) + sum_values(args...);
}

int main()
{
	cout << sum_values(1.1, 2, 'A') << endl;
	return 0;
}