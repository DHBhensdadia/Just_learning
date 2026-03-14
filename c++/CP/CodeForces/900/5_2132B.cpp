#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

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
    
    // counting digits in n
    int digits{0};
    for(ll i = n; i != 0; i /= 10){
        digits++;
    }

    // calculation for x
    vector<ll> x;
    int xcount{0};
    for (int i = 1; i <= digits; i++){
        if(n % (ll)(1 + (ll)pow(10, i)) == 0){
            xcount++;
            x.push_back(n / (ll)(1 + (ll)pow(10, i)));
        }
    }

    // printing
    reverse(x.begin(), x.end());
    cout << xcount << endl;
    if(xcount != 0){
        for(auto i : x){
            cout << i << ' ';
        }
        cout << endl;
    }

}