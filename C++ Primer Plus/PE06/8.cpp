#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("test.txt");
    if (!inFile.is_open())
    {
        cout << "파일이 없습니다.\n";
        exit(EXIT_FAILURE);
    }
    
    string str;
    unsigned cnt = 0;
    while (inFile.good())
    {
        inFile >> str;
        cnt++;
    }
    if (inFile.eof())
        cout << "파일 끝!" << endl;
    else if (inFile.fail())
        cout << "타입 안 맞음" << endl;
    else
        cout << "원인 불명" << endl;

    cout << "문자 개수: " << cnt << endl;
    inFile.close();
    return 0;
}