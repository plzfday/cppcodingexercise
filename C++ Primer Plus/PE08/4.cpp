#include <iostream>
#include <cstring>
using namespace std;

struct stringy
{
    char* str;
    int ct;      // '\0'을 제외한 문자열의 길이
};

void set(stringy& src, const char* str);
void show(const stringy& src, unsigned count = 1);
void show(const char* str, unsigned count = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be";
    
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    return 0;
}

void set(stringy & src, const char * str)
{
    int strSize = strlen(str);
    src.str = new char[strSize + 1];
    strcpy(src.str, str);
    src.ct = strSize;
}

void show(const stringy & src, unsigned count)
{
    for (int i = 0; i < count; ++i)
        cout << src.str << endl;
}

void show(const char * str, unsigned count)
{
    for (int i = 0; i < count; ++i)
        cout << str << endl;
}
