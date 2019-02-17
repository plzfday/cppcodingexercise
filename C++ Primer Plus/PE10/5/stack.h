#ifndef STACK_H_
#define STACK_H_

struct Customer
{
    char FullName[35];
    double Payment;
};

typedef Customer Item;

class Stack
{
private:
    enum { MAX = 10 };
    Item mItems[MAX];
    int mTop;
public:
    Stack();
    bool IsEmpty() const;
    bool IsFull() const;
    // push()는 스택이 가득 차 있으면 false를, 아니면 true를 리턴한다
    bool Push(const Item& item);
    // pop()은 스택이 비어 있으면 false를, 아니면 true를 리턴한다
    bool Pop(Item & item);
};

#endif // !STACK_H_
