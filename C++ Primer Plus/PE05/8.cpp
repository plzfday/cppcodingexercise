#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    cout << "영어 단어들을 입력하십시오 (끝내려면 done을 입력) : \n";
    char voca[100];
    int cnt = 0;
    cin >> voca;
    while (strcmp(voca, "done"))
    {
        cnt++;
        cin >> voca;
    }
    cout << "총 " << cnt << "단어가 입력되었습니다.";
    return 0;
}