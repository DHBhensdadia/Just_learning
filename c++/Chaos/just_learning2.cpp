#include <iostream>

using namespace std;

int x{10}; //globle variable

int main()
{
    int val{14};
    cout << val << "\n";

    int x{4};
    cout << x << endl;
    cout << ::x << endl;      // scope resolution oparator

    

    return 0;

}