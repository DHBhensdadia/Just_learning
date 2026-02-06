#include <bits/stdc++.h>

using namespace std;

int main(){
    int n_t;
    cin >> n_t;

    while(n_t--){
        int pla, y, r;
        cin >> pla >> y >> r;

        int ans = y/2 + r;
        cout << ((pla < ans) ? pla : ans) << endl;
    }

    return 0;
}