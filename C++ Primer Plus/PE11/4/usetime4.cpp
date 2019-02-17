#include "mytime4.h"

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida¿Í Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = 1.7 * aida;
    cout << "1.7 * Aida: " << temp << endl;
    cout << "Tosca * 10: " << tosca * 10 << endl;

    return 0;
}