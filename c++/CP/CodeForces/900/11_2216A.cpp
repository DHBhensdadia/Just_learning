#include <bits/stdc++.h>

using namespace std;


void solution(void){
    int n, k;
    cin >> n >> k;
    vector<int> kv;
    vector<int> bv;

    for(int i = 0; i < k; i++){
        int temp;
        cin >> temp;
        kv.emplace_back(temp);
    }

    int nop = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        bv.emplace_back(temp);
        
        nop += ((k+1 > temp) ? k+1-temp : 0);
    }

    cout << nop << endl;

    if (nop > 1000){
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n; i++){
        int top = ((bv[i] < k+1) ? k+1-bv[i] : 0);
        for (int j= 0; j < top; j++){
            cout << i+1 << ' '; 
        }
    }

    cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nt;
    cin >> nt;
    while(nt--){
        solution();
    }
}