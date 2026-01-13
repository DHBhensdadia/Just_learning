#include <bits/stdc++.h>
using namespace std;

int main(){

    int count = 0;
    int max = 0;

    string str;
    cin >> str;

    for (string::iterator it = str.begin() + 1; it != str.end(); it ++){
        if (*it == *(it - 1))
        {
            count++;
        }else{
            count++;
            if (max < count)    max = count;
            count = 0;
        }
    }

    if (max < ++count)    max = count;

    cout << max;
    return 0;
}