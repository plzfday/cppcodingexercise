#include <iostream>
#include "list.h"

List::List()
{
    mSize = 0;
}

void List::Add(Item& item)
{
    if (!IsFull())
        mItems[mSize++] = item;
    else
        std::cerr << "List is full.\n";
}

void List::Remove()
{
    if (!IsEmpty())
        mSize--;
    else
        std::cerr << "List is empty.\n";
}

bool List::IsEmpty() const
{
    return mSize == 0;
}

bool List::IsFull() const
{
    return mSize == MAX;
}

void List::ShowList() const
{
    std::cout << "[List]\n";
    for (int i = 0; i < mSize; ++i)
        std::cout << mItems[i] << " ";
    std::cout << std::endl;
}
