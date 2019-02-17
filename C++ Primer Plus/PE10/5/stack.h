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
    // push()�� ������ ���� �� ������ false��, �ƴϸ� true�� �����Ѵ�
    bool Push(const Item& item);
    // pop()�� ������ ��� ������ false��, �ƴϸ� true�� �����Ѵ�
    bool Pop(Item & item);
};

#endif // !STACK_H_
