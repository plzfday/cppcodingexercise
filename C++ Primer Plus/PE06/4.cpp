#include <iostream>
using namespace std;

const int strsize = 20, customer_size = 5;

struct bop {
    char fullname[strsize];      // 실명
    char title[strsize];         // 직함
    char bopname[strsize];       // BOP 아이디
    int preference;              // 0 = fullname, 1 = title, 2 = bopname
};

void show_menu();
void show_fullname(bop * customer);
void show_title(bop * customer);
void show_bopname(bop * customer);
void show_preferenced_contents(bop * customer);

int main()
{
    bop sites[customer_size] = {
        {"Wimp Macho", "Programmer", "WM", 0},
        {"Raki Rhodes", "Junior Programmer", "RR", 1},
        {"Celia Laiter", "Designer", "MIPS", 2},
        {"Hoppy Hipman", "Analyst Trainee", "HH", 2},
        {"Pat Hand", "Senior Programmer", "LOOPY", 2}
    };

    char ch;
    show_menu();
    while (cin.get(ch))
    {
        bool outta_here = false;
        switch (ch)
        {
        case 'a':
            show_fullname(sites);
            break;
        case 'b':
            show_title(sites);
            break;
        case 'c':
            show_bopname(sites);
            break;
        case 'd':
            show_preferenced_contents(sites);
            break;
        case 'q':
            outta_here = true;
        }
        if (outta_here)
            break;
        cout << "원하는 것을 선택하십시오: ";
        cin.get();
    }

    return 0;
}

void show_menu()
{
    cout << "Benevolent Order of Programmers\n"
        "a. 실명으로 열람           b. 직함으로 열람\n"
        "c. BOP 아이디로 열람       d. 회원이 지정한 것으로 열람\n"
        "q. 종료";
    cout << "\n원하는 것을 선택하십시오: ";
}

void show_fullname(bop * customer)
{
    for (int i = 0; i < customer_size; ++i)
        cout << customer[i].fullname << endl;
}

void show_title(bop * customer)
{
    for (int i = 0; i < customer_size; ++i)
        cout << customer[i].title << endl;
}

void show_bopname(bop * customer)
{
    for (int i = 0; i < customer_size; ++i)
        cout << customer[i].bopname << endl;
}

void show_preferenced_contents(bop * customer)
{
    for (int i = 0; i < customer_size; ++i)
    {
        int preference = customer[i].preference;
        switch (preference)
        {
        case 0:
            cout << customer[i].fullname << endl;
            break;
        case 1:
            cout << customer[i].title << endl;
            break;
        case 2:
            cout << customer[i].bopname << endl;
            break;
        default:
            cout << "미지정\n";
            break;
        }
    }
}
