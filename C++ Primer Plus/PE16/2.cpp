#include <cctype>
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& st);
string eraseExtraChar(const string& st);

int main()
{
	string s = "Madam, I'm Adam";
	if (isPalindrome(s))
	{
		cout << "This is palindrome.\n";
	}
	else
	{
		cout << "This is not palindrome.\n";
	}
	return 0;
}

bool isPalindrome(const string & st)
{
	string ret = eraseExtraChar(st);
	cout << "문자열을 새로 바꿨습니다: " << ret << endl;
	size_t strLength= ret.size();
	for (int i = 0; i < double(strLength) / 2.0; ++i)
	{
		if (ret[i] != ret[strLength - i - 1])
		{
			return false;
		}
	}
	return true;
}

string eraseExtraChar(const string& st)
{
	string ret = "";
	for (auto& i : st)
	{
		if (isalpha(i))
		{
			ret += tolower(i);
		}
	}
	return ret;
}