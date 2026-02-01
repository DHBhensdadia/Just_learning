#include <bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin >> n;

    long ans = 1;
    long mod = 1000000007;
    for (int i = 0; i < n; i++){
        ans *= 2;
        ans %= mod;
    }

    cout << ans;
    return 0;
    

}