#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T & t) : cutoff(t) {}
	bool operator()(const T & v) { return v > cutoff; }
};

auto outint = [](int n) { std::cout << n << " "; };

int main()
{
	using std::list;
	using std::cout;
	using std::endl;

	list<int> yadayada = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> etcetera{ 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };

	cout << "원래의 리스트:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if([](int x) { return x > 100; });  
	etcetera.remove_if([](int x) { return x > 200; });
	cout << "정비된 리스트:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	return 0;
}
