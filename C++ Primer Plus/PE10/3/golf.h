#ifndef GOLF_H_
#define GOLF_H_

class Golf
{
private:
    static const int LEN = 40;
    char mFullName[LEN];
    int mHandicap;
public:
    // 생성자
    Golf() { mFullName[0] = '\0', mHandicap = 0; }
    Golf(const char * name, int hc);

    // 대화식 버전:
    // 이 함수는 사용자에게 이름과 핸디캡을 묻는다
    // g의 멤버들을 입력된 값으로 설정한다
    // 이름이 입력되면 1을 리턴하고, 이름이 빈 문자열이면 0을 리턴한다
    int SetGolf();

    // 이 함수는 handicap을 새로운 값으로 설정한다
    void Handicap(int hc);

    // 이 함수는 golf 구조체의 내용을 출력한다
    void ShowGolf() const;
};

#endif // !GOLF_H_
