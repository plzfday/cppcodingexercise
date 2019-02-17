#include <iostream>
using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void func_a(box box);
void func_b(box* box);

int main()
{
    box test1 = { "plzfday", 170.4, 30, 50, 0 };
    func_b(&test1);
    func_a(test1);
    return 0;
}

void func_a(box box)
{
    cout << "Maker: " << box.maker << endl;
    cout << "Height: " << box.height << endl;
    cout << "Width: " << box.width << endl;
    cout << "Length: " << box.length << endl;
    cout << "Volume: " << box.volume << endl;
}

void func_b(box * box)
{
    box->volume = box->height * box->width * box->length;
}
