#include <iostream>
#include <cstdlib>
using namespace std;

void show_menu();
void ask_again();

int main()
{
    char ch;
    show_menu();
    while (cin.get(ch))
    {
        bool showAgain = false;
        switch (ch)
        {
        case 'c':
        case 'C':
            cout << "카메라는 비쌉니다.\n";
            break;
        case 'p':
        case 'P':
            cout << "피아노를 잘 치면 멋집니다.\n";
            break;
        case 't':
        case 'T':
            cout << "단풍나무는 잎이 별처럼 생겼습니다.\n";
            break;
        case 'g':
        case 'G':
            cout << "게임은 재미있습니다.\n";
            break;
        case 'q':
        case 'Q':
            cout << "프로그램 종료";
            exit(EXIT_SUCCESS);
        default:
            showAgain = true;
            break;
        }
        if (showAgain)
            ask_again();
        else
            show_menu();
        cin.get();
    }
    return 0;
}

void show_menu()
{
    cout << "다음 선택 사항 중에서 하나를 선택하십시오. (끝내려면 q)\n"
        "c) camera        p) pianist\n"
        "t) tree          g) game\n";
}

void ask_again()
{
    cout << "c, p, t, g 중에서 하나를 선택하십시오. (끝내려면 q) : ";
}