#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;

    while (n--){
        string str;
        cin >> str;
        
        sort(str.begin(), str.end());
        reverse(str.begin(), str.end());

        cout << str << endl;
    }

    return 0;
}