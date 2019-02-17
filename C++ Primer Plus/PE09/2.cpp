#include <iostream>
#include <string>

void strcount(const std::string & str);

int main()
{
    using namespace std;
    string input;
    char next;

    cout << "�������� �� ���� �Է��Ͻʽÿ�:\n";
    getline(cin, input);
    while (input != "")
    {
        strcount(input);
        cout << "���� ���� �Է��Ͻʽÿ� (�������� �� ���� �Է�):\n";
        getline(cin, input);
    }
    cout << "���α׷��� �����մϴ�.\n";
    return 0;
}

void strcount(const std::string & str)
{
    using namespace std;
    static int total = 0;
    int count = str.size();

    cout << "\"" << str << "\"���� ";
    
    total += count;
    cout << count << "���� ���ڰ� �ֽ��ϴ�.\n";
    cout << "���ݱ��� �� " << total << "���� ���ڸ� �Է��ϼ̽��ϴ�.\n";
}
