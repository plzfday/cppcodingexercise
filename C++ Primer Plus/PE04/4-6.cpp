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
    CandyBar candies[3] = {
        {"Mocha Munch", 2.3, 350},
        {"Dunkey", 3.5, 283 },
        {"Donuts", 9.7, 314}
    };

    cout << "상품 1[" << candies[0].name << "] - 중량: " << candies[0].weight << ", 칼로리: " << candies[0].calorie << endl;
    cout << "상품 2[" << candies[1].name << "] - 중량: " << candies[1].weight << ", 칼로리: " << candies[1].calorie << endl;
    cout << "상품 3[" << candies[2].name << "] - 중량: " << candies[2].weight << ", 칼로리: " << candies[2].calorie << endl;
    return 0;
}