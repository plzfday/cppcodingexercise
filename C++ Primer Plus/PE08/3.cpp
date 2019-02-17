#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "문자열을 입력하시오 (끝내려면 q): ";
    while (getline(cin, str) && str != "q")
    {
        for (char c : str)
            cout << char(toupper(c));
        cout << "\n문자열을 입력하시오 (끝내려면 q): ";
    }
    cout << "끝.";
    return 0;
}