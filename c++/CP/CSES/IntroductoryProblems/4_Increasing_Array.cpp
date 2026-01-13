#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;

    vector<ll> v;
    v.reserve(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    ll ans = 0;
    for (int i = 1; i < n; i++){
        if (v[i - 1] > v[i]){
            ans += v[i -1] - v[i];
            v[i] = v[i -1];
        }
    }

    cout << ans;

    return 0;
}