#include <iostream>
#include <cstring>
#include <new>

struct chaff
{
    char dross[20];
    int slag;
};

char buffer[100];
int main()
{
    using namespace std;
    chaff * p1;
    p1 = new (buffer) chaff[2];
    strcpy_s(p1[0].dross, "dress");
    p1[0].slag = 13;
    strcpy_s(p1[1].dross, "dress2123");
    p1[1].slag = 21233;

    for (int i = 0; i < 2; ++i)
        cout << "Dross: " << p1[i].dross << ", Slag: " << p1[i].slag << endl;
    return 0;
}