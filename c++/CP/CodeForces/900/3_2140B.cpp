#include <bits/stdc++.h>
using namespace std;
# define ll long long

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
 
    ll n;
    cin >> n;

    for(ll i = 1; ; i++){
        ll x = n;
        ll y = i;
        
         // y length checker (integer-safe)
        ll temp = y;
        ll ysize = 0;
        do {
            ++ysize;
            temp /= 10;
        } while (temp != 0);

        // compute 10^ysize exactly as integer
        ll mult = 1;
        for (ll k = 0; k < ysize; ++k) mult *= 10;

        // combined number
        ll combined = x * mult + y;

        if (combined % (x + i) == 0) {
            cout << i << '\n';
            break;
        }
    }

}