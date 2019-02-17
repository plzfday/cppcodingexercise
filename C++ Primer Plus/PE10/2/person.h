#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person
{
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
public:
    Person() { lname = "", fname[0] = '\0'; }
    Person(const std::string& ln, const char* fn = "Heyyou");
    void Show() const;          // 이름 성씨 형식
    void FormalShow() const;    // 성씨, 이름 형식
};

#endif // !PERSON_H_
