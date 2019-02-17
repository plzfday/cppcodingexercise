#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVowel(char);

int main()
{
    string ch;
    unsigned vowel = 0, consonant = 0, others = 0;
    
    cout << "단어들을 입력하시오 (끝내려면 q):\n";
    while (cin >> ch)
    {
        if (ch == "q")
            break;
        if (isalpha(ch[0]))
        {
            if (isVowel(ch[0]))
                vowel++;
            else
                consonant++;
        }
        else
            others++;
    }
    cout << "모음으로 시작하는 단어 수: " << vowel << endl;
    cout << "자음으로 시작하는 단어 수: " << consonant << endl;
    cout << "기타: " << others << endl;
    return 0;
}

bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'A' || ch == 'o' || ch == 'O' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'u' || ch == 'U')
        return true;
    return false;
}