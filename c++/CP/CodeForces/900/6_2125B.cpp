#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solution(void);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nt; cin >> nt;
    while (nt--){
        solution();
    }

}

void solution(void){

    ll a, b, k;
    cin >> a >> b >> k;

    // compute gcd and required repetitions
    ll g = std::gcd(a, b);
    ll needA = (a + k - 1) / k; // ceil(a/k)
    ll needB = (b + k - 1) / k; // ceil(b/k)
    ll M = max(needA, needB);

    if (g >= M) cout << 1 << '\n';
    else cout << 2 << '\n';
}