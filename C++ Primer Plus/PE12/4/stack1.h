#ifndef STACK1_H_
#define STACK1_H_

typedef unsigned long Item;

class Stack
{
private:
    enum { MAX = 10 };    // 클래스 용 상수
    Item* pitems;         // 스택 항목들을 저장한다
    int size;             // 스택에 들어 있는 원소의 수
    int top;              // 스택의 꼭대기 항목을 나타낸다
public:
    Stack(int n = MAX);
    Stack(const Stack& st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    // push()는 full이면 false, 아니면 true 리턴
    bool push(const Item& item);
    // pop()은 empty면 false를, 아니면 true 리턴
    bool pop(Item& item);
    Stack& operator=(const Stack& st);
};

#endif // !STACK1_H_
