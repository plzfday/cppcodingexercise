#ifndef STRING2_H_
#define STRING2_H_

#include <iostream>

class String
{
private:
    char* str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
// �����ڿ� ��Ÿ �޼���
    String(const char* s);
    String();
    String(const String& st);
    ~String();
    int length() const { return len; }
    void stringlow();
    void stringup();
    int has(const char c);
// �����ε� ������ �޼���
    const String& operator=(const String& st);
    const String& operator=(const char* s);
    const String operator+(const String& st) const;
    const String operator+(const char* st) const;
    char& operator[] (int i);
    const char& operator[](int i) const;
// �����ε� ������ ������
    friend bool operator<(const String& st1, const String& st2);
    friend bool operator>(const String& st1, const String& st2);
    friend bool operator==(const String& st1, const String& st2);
    friend const String operator+(const char* st1, const String& st2);
    friend std::ostream& operator<<(std::ostream& os, const String& st);
    friend std::istream& operator>>(std::istream& is, String& st);
// static �Լ�
    static int HowMany();
};

#endif // !STRING2_H_