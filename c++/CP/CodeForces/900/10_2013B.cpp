#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long

void solution(void);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nt; cin >> nt;
    while (nt--){
        solution();
    }

    return 0;
}

void solution(void){
 
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++){
    
        cin >> v[i];
    }

    
    for(ll i= 0; i < n - 2; i++){
        v[n - 2] -= v[i];
    }

    cout << v[n - 1] - v[n - 2] << endl;
}