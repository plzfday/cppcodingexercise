#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    char ch;
    while (cin.get(ch) && ch != '@')
    {
        if (islower(ch))
            cout << char(toupper(ch));
        else if (isupper(ch))
            cout << char(tolower(ch));
    }
    return 0;
}