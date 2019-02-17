#include <iostream>
using namespace std;
const int Max = 5;

// function prototypes
double* fill_array(double* begin, double* end);
void show_array(const double* begin, const double* end);  // don't change data
void revalue(double* begin, double* end);

int main()
{
    double properties[Max];

    double* end = fill_array(properties, properties + Max);
    show_array(properties, end);
    revalue(properties, end);
    show_array(properties, end);
    return 0;
}

double* fill_array(double* begin, double* end)
{
    double temp;
    double* pt;
    int i = 0;
    for (pt = begin; pt != end; pt++)
    {
        cout << "Enter value #" << ++i << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)     // signal to terminate
            break;
        *pt = temp;
    }
    return pt;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double* begin, const double* end)
{
    using namespace std;
    int i = 0;
    for (const double* pt = begin; pt != end; pt++)
    {
        cout << "Property #" << ++i << ": $";
        cout << *pt << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double* begin, double* end)
{
    double r;
    cout << "재평가율: ";
    cin >> r;
    for (double* pt = begin; pt != end; pt++)
        *pt *= r;
}
