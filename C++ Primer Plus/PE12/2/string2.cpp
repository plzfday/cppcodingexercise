#include <cstring>
#include <cctype>
#include "string2.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st)
{
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    num_strings++;
}

String::~String()
{
    --num_strings;
    delete[] str;
}

void String::stringlow()
{
    for (int i = 0; i < std::strlen(str); ++i)
    {
        str[i] = tolower(str[i]);
    }
}

void String::stringup()
{
    for (int i = 0; i < std::strlen(str); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

int String::has(const char c)
{
    int count = 0;
    for (int i = 0; i < std::strlen(str); ++i)
    {
        if (c == str[i])
            count++;
    }
    return count;
}

const String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

const String & String::operator=(const char * s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

const String String::operator+(const String & st) const
{
    int nLen = len + st.len;
    char* newStr = new char[nLen + 1];
    std::strcpy(newStr, str);
    std::strcat(newStr, st.str);
    String temp(newStr);
    delete[] newStr;
    return temp;
}

const String String::operator+(const char * st) const
{
    int nLen = len + std::strlen(st);
    char* newStr = new char[nLen + 1];
    std::strcpy(newStr, str);
    std::strcat(newStr, st);
    String temp(newStr);
    delete[] newStr;
    return temp;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
    return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

const String operator+(const char * st1, const String & st2)
{
    String temp(st1);
    return temp + st2;
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
    os << st.str;
    return os;
}

std::istream & operator>>(std::istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
