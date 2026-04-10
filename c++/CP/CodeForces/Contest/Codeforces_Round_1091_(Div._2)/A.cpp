#include <bits/stdc++.h>
using namespace std;

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
    
    int n, k;

    cin >> n >> k;

    vector<int> v(n);
    int sum = 0;
    for (auto & i : v){
        cin >> i;
        sum += i;
    }

    if ( (sum & 1) || ((n*k)%2 == 0) ){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }

}