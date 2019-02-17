#ifndef STACK1_H_
#define STACK1_H_

typedef unsigned long Item;

class Stack
{
private:
    enum { MAX = 10 };    // Ŭ���� �� ���
    Item* pitems;         // ���� �׸���� �����Ѵ�
    int size;             // ���ÿ� ��� �ִ� ������ ��
    int top;              // ������ ����� �׸��� ��Ÿ����
public:
    Stack(int n = MAX);
    Stack(const Stack& st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    // push()�� full�̸� false, �ƴϸ� true ����
    bool push(const Item& item);
    // pop()�� empty�� false��, �ƴϸ� true ����
    bool pop(Item& item);
    Stack& operator=(const Stack& st);
};

#endif // !STACK1_H_
