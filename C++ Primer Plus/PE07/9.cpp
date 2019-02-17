#include <iostream>
using namespace std;

const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
// getinfo()는 두 개의 전달인자를 취한다. 하나는 student 구조체
// 배열의 첫 번째 원소를 지시하는 포인터이고, 다른 하나는
// 그 배열의 원소 수를 나타내는 int 값이다. 이 함수는 학생들과 
// 관련된 데이터를 요구하여 배열에 저장하고, 배열이 다 찼거나
// 학생 이름에 빈 줄이 입력되면 종료된다. 이 함수는 배열의 
// 실제로 채워진 원소 수를 리턴한다.
int getinfo(student pa[], int n);

// display1()은 student 구조체를 전달인자로 취하며
// 그 구조체의 내용을 출력한다
void display1(student st);

// display2()는 student 구조체의 주소를 전달인자로 취하며
// 그 구조체의 내용을 출력한다
void display2(const student * ps);

// display3()은 student 구조체 배열의 첫 번째 원소의 주소와
// 배열의 원소 수를 전달인자로 취하며, 구조체들의 내용을 출력한다
void display3(const student pa[], int n);

int main()
{
    cout << "학급의 학생 수를 입력하십시오: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    cout << "프로그램을 종료합니다.\n";
    return 0;
}

int getinfo(student pa[], int n)
{
    int i = 0;
    while (i < n)
    {
        cout << "name: ";
        cin.getline(pa[i].fullname, SLEN);
        if (!(strcmp(pa[i].fullname, "")))
            break;
        cout << "hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        cout << "level: ";
        (cin >> pa[i].ooplevel).get();
        i++;
    }
    cout << endl;
    return i;
}

void display1(student st)
{
    cout << "name: " << st.fullname << endl;
    cout << "hobby: " << st.hobby << endl;
    cout << "level: " << st.ooplevel << endl;
}

void display2(const student * ps)
{
    cout << "name: " << ps->fullname << endl;
    cout << "hobby: " << ps->hobby << endl;
    cout << "level: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "#" << i + 1 << " student\n";
        display2(&pa[i]);
    }
}
