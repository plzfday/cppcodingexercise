#include <iostream>
#include "list.h"

int main()
{
    List list;
    for (int i = 1; i <= 20; ++i)
        list.Add(i);
    list.ShowList();
    for (int i = 1; i <= 10; ++i)
        list.Remove();
    list.ShowList();
    return 0;
}