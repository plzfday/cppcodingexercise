#include <iostream>
#include "golf.h"

int main()
{
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    golf andy;
    setgolf(andy);
    showgolf(ann);
    showgolf(andy);
    return 0;
}