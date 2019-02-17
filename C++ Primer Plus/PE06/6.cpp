#include <iostream>
#include <string>
using namespace std;

struct Donation
{
    string name;
    double money;
};

int main()
{
    int n;
    cout << "몇 분?: ";
    (cin >> n).get();
    Donation* donation = new Donation[n];
    
    for (int i = 0; i < n; ++i)
    {
        cout << "#" << i + 1 << " 기부자: ";
        getline(cin, donation[i].name);
        cout << "#" << i + 1 << " 기부금: ";
        (cin >> donation[i].money).get();
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