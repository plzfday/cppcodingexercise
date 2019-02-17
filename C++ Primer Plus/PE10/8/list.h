#ifndef LIST_H_
#define LIST_H_

typedef unsigned long Item;

class List
{
private:
    enum {MAX = 20};
    Item mItems[MAX];
    unsigned mSize;
public:
    List();
    void Add(Item& item);
    void Remove();
    bool IsEmpty() const;
    bool IsFull() const;
    void ShowList() const;
};

#endif // !LIST_H_
