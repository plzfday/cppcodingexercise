#include "stack.h"

Stack::Stack()
{
    mTop = 0;
}

bool Stack::IsEmpty() const
{
    return mTop == 0;
}

bool Stack::IsFull() const
{
    return mTop == MAX;
}

bool Stack::Push(const Item & item)
{
    if (mTop < MAX)
    {
        mItems[mTop++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::Pop(Item & item)
{
    if (mTop > 0)
    {
        item = mItems[--mTop];
        return true;
    }
    else
        return false;
}
