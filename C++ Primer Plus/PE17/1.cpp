#include <iostream>
#include <cstring>
const int LEN = 100;
int main()
{
	using namespace std;
	char str[LEN];
	cin.get(str, LEN, '$');
	cout << "���� ��: " << strlen(str) << endl;
	cout << "������ ���ڰ� $���� Ȯ��: " << char(cin.get()) << endl;
	return 0;
}