#include <iostream>
using namespace std;
const int StrSize = 20;
void print(const char* str, int n = 0);

int main()
{
    char str[StrSize];

    cout << "문자 입력: ";
    cin.get(str, StrSize);
    print(str);
    print(str, 10);
    for (int i = 0; i < 3; ++i)
        print(str, 20);
    return 0;
}

void print(const char * str, int n)
{
    static int calledCount = 0;
    calledCount++;
    if (n)
    {
        for (int i = 0; i < calledCount; ++i)
            cout << calledCount << "번 째 출력" << str << endl;
    }
    else
    {
        cout << calledCount << "번 째 출력" << str << endl;
    }
}
