#include <iostream>
#include <cmath>
#include "exc_mean.h"

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    double x, y, z;

    cout << "�� ���� �Է��Ͻʽÿ�: ";
    while (cin >> x >> y)
    {
        try {                  // try ����� ����
            z = hmean(x,y);
            cout << x << ", " << y << "�� ��ȭ����� "
                 << z << "�Դϴ�.\n";
            cout << x << ", " << y << "�� ��������� "
                 << gmean(x,y) << "�Դϴ�.\n";
            cout << "�ٸ� �� ���� �Է��Ͻʽÿ�(�������� q): ";
        }				// try ����� ��
        catch (bad_hmean & bg)    	// catch ����� ����
        {
			bg.what();
            cout << "�ٽ� �Ͻʽÿ�.\n";
            continue;
        }                  
        catch (bad_gmean & hg) 
        {
            cout << hg.what();
            cout << "�˼��մϴ�. �� �̻� ������ �� �����ϴ�.\n";
            break;
        } 				// catch ����� ��
    }
    cout << "���α׷��� �����մϴ�.\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean();
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return std::sqrt(a * b); 
}
