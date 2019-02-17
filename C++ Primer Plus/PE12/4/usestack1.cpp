// usestack1.cpp -- Stack 클래스를 테스트한다
#include <iostream>
using namespace std;
#include <cctype>		// 또는 ctype.h
#include "stack1.h"

void showStack(Stack & st);

int main()
{
    char c;
    unsigned long po;
    int st_size;

    cout << "처리하지 않고 최대로 쌓아 둘 수 있는 주문서 수: ";
    while (!(cin >> st_size))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "처리하지 않고 최대로 쌓아 둘 수 있는 주문서 수: ";
    }
    Stack st1(st_size);		// st_size개의 원소를 가지는 스택을 동적으로 생성한다

    cout << "주문서 추가(A)    주문서 처리(P)    미처리 주문서 확인(C)    프로그램 종료(Q)\n";
    while (cin >> c && toupper(c) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(c))
        {
            cout << '\a';
            continue;
        }
        switch (c)
        {
        case 'A':
        case 'a': cout << "추가할 주문서의 번호를 입력하십시오: ";
            cin >> po;
            if (st1.isfull())
                cout << "스택이 가득 차 있습니다.\n";
            else
                st1.push(po);
            break;
        case 'P':
        case 'p': if (st1.isempty())
            cout << "스택이 비어 있습니다.\n";
                  else
        {
            st1.pop(po);
            cout << "#" << po << " 주문서를 처리했습니다.\n";
        }
                  break;
        case 'C':
        case 'c': Stack st2;
            st2 = st1;				// 대입 연산자를 사용한다
            showStack(st2);
            Stack st3(st1);			// 복사 생성자를 사용한다
            showStack(st3);
            break;
        }
        cout << "주문서 추가(A)    주문서 처리(P)    미처리 주문서 확인(C)    프로그램 종료(Q)\n";
    }
    cout << "프로그램을 종료합니다.\n";
    return 0;
}

void showStack(Stack & st)
{
    Item value;

    if (st.isempty())
        cout << "스택이 비어 있습니다.\n";
    else
    {
        while (st.pop(value))
            cout << value << "\t";
        cout << "\n";
    }
}
