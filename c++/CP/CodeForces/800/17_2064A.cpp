#include <bits/stdc++.h>

using namespace std;

int main(){
    int nt;
    cin >> nt;
    while(nt--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int count = 0;

        if (s[0] == 0){
            for (int i = 1; i < n; i++){
                if (s[i - 1] != s[i]){
                    count ++;
                }
            }

            cout << count << endl;
        }else {
            
        }
        
    }
}