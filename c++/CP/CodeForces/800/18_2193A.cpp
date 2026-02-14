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
    int n, s, x;
    cin >> n >> s >> x;

    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.emplace_back(temp);
    }

    int sum = accumulate(v.begin(), v.end(), 0);

    if ((s - sum) % x == 0 && s >= sum){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }

}