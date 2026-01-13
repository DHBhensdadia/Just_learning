#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll in;
    cin >> in;
    cout << in << ' ';

    while (in != 1)
    {
        if (in & 1)
        {
            in = in * 3 + 1;
            cout << in << ' ';
        }
        else
        {
            in /= 2;
            cout << in << ' ';
        }
    }

    return 0;
}
