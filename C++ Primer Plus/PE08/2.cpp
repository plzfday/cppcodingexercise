#include <iostream>
#include <cstring>
using namespace std;

const int brandNameSize = 20;
struct CandyBar
{
    char brandName[brandNameSize];
    double weight;
    int calorie;
};

void SetCandyBar(CandyBar& product, const char* str = "Millennium", double weight = 2.85, int calorie = 350);
void ShowCandyBar(const CandyBar& product);

int main()
{
    CandyBar p1 = { "CCP_LOVER", 30.4, 1000 };
    ShowCandyBar(p1);
    SetCandyBar(p1);
    ShowCandyBar(p1);
    return 0;
}

void SetCandyBar(CandyBar & product, const char * str, double weight, int calorie)
{
    strcpy_s(product.brandName, brandNameSize, str);
    product.weight = weight;
    product.calorie = calorie;
}

void ShowCandyBar(const CandyBar & product)
{
    cout << product.brandName << ' ' << product.weight << ' ' << product.calorie << endl;
}
