#include <bits/stdc++.h>

using namespace std;

int main(){
    int ttt;
    cin >> ttt;
    while(ttt--){
        int n, h, l;
        cin >> n >> h >> l;
        
        vector<int> v(n);
        for(auto &i : v){
            cin >> i;
        }
    
        if (n & 1){
            auto it = max_element(v.begin(), v.end());
            if (it != v.end()) v.erase(it);
            n--;
        }

        // same , diff calculator
        int small = h < l ? h : l;
        int big = h < l ? l : h;

        int same = 0, diff = 0;
        
        for(int i = 0; i < n; i++){
            if(v[i] <= small){
                same++; 
            }else if (v[i] <= big){
                diff++;
            }
        }

        if (same >= diff){
            cout << ((same - diff) / 2 + diff) << endl;
        }else {
            cout << same << endl;
        }
    }

    return 0;
}