#include <bits/stdc++.h>

using namespace std;

int main(){
    int nt;
    cin >> nt;
    while (nt--){
        string s;
        cin >> s;

        int len = s.length();
        bool flag = false;
        for (int i = 1; i < len;i++){
            if (s[i - 1] == s[i]){
                flag = true;
                break;
            }
        }

        if (flag){
            cout << 1 << endl;
        }else {
            cout << len << endl;
        }
    }

    return 0;
}