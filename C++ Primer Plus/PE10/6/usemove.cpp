#include <iostream>
#include "move.h"

int main()
{
    Move move = Move(3, 4);
    move.showmove();
    move.add(Move(15, 29)).showmove();
    move.reset();
    move.showmove();
    return 0;
}