#include <bits/stdc++.h>

using namespace std;

int main (){

    int tt;
    cin >> tt;
    while(tt--){
        int n; 
        cin >> n;

        vector<int> v(n);
        v[0] = 1;
        for (int i = 1; i < n; i++){
            if (i & 1){
                v[i] = v[i - 1] + n - i;
            }else {
                v[i] = v[i - 1] - n + i;
            }
        }

        reverse(v.begin(), v.end());
        
        for (auto &i : v){
            cout << i << ' ';
        }

        cout << endl;
    }
}