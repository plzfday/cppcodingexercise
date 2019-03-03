#include <iostream>
#include <cstring>
const int LEN = 100;
int main()
{
	using namespace std;
	char str[LEN];
	cin.get(str, LEN, '$');
	cout << "문자 수: " << strlen(str) << endl;
	cout << "마지막 문자가 $인지 확인: " << char(cin.get()) << endl;
	return 0;
}