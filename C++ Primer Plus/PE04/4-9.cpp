#include <iostream>
#include <string>
struct CandyBar
{
    std::string name;
    double weight;
    int calorie;
};
int main()
{
    using namespace std;
    CandyBar* candies = new CandyBar[3]{
        {"C", 1.2, 23},
        {"D", 2.3, 2123},
        {"CD", 123.2, 87}
    };

    cout << "상품 1[" << candies[0].name << "] - 중량: " << candies[0].weight << ", 칼로리: " << candies[0].calorie << endl;
    cout << "상품 2[" << candies[1].name << "] - 중량: " << candies[1].weight << ", 칼로리: " << candies[1].calorie << endl;
    cout << "상품 3[" << candies[2].name << "] - 중량: " << candies[2].weight << ", 칼로리: " << candies[2].calorie << endl;
    return 0;
}