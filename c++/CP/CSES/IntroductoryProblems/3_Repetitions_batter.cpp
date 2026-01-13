#include <bits/stdc++.h>
using namespace std;

int main(){

    int count = 0;
    int max = 0;

    string str;
    cin >> str;

    char last = 'o';
    for (char t : str){
        if (t == last)
        {
            count++;
        }else{
            last = t;
            count++;
            if (max < count)    max = count;
            count = 0;
        }
    }

    if (max < ++count)    max = count;

    cout << max;
    return 0;
}