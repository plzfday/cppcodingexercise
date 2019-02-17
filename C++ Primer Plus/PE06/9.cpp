#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Donation
{
    string name;
    double money;
};

int main()
{
    int n;
    ifstream inFile;
    inFile.open("test.txt");
    if (!inFile.is_open())
    {
        cout << "파일 없음\n";
        exit(EXIT_FAILURE);
    }
    
    (inFile >> n).get();
    Donation* donation = new Donation[n];

    for (int i = 0; i < n; ++i)
    {
        getline(inFile, donation[i].name);
        (inFile >> donation[i].money).get();
    }

    int count = 0;
    cout << "고액 기부자\n";
    for (int i = 0; i < n; ++i)
    {
        if (donation[i].money >= 10000)
        {
            cout << donation[i].name << " - " << donation[i].money << endl;
            count++;
        }
    }

    cout << "소액 기부자\n";
    for (int i = 0; i < n; ++i)
    {
        if (donation[i].money < 10000)
        {
            cout << donation[i].name << " - " << donation[i].money << endl;
            count++;
        }
    }
    if (!count)
        cout << "기부자가 없습니다.\n";

    delete[] donation;
    return 0;
}