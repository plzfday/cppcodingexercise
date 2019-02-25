#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& st);

int main()
{
	string s = "toamaot";
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
	// first implementation
	for (int i = 0; i < double(st.size()) / 2.0; ++i)
	{
		if (st[i] != st[st.size() - i - 1])
		{
			return false;
		}
	}
	return true;

	// Answer code
	/*string compareString(st.rbegin(), st.rend());
	return (compareString == st);*/
}
