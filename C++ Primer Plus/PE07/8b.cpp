#include <iostream>
#include <string>
const int Seasons = 4;
const char* Snames[] = { "Spring", "Summer", "Fall", "Winter" };

struct array {
    double expenses[Seasons];
};

void fill(array * pa);
void show(array da);
int main()
{
    array expenses{};
    fill(&expenses);
    show(expenses);
    return 0;
}

void fill(array * pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> pa->expenses[i];
    }
}

void show(array da)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << da.expenses[i] << '\n';
        total += da.expenses[i];
    }
    std::cout << "Total: $" << total << '\n';
}
