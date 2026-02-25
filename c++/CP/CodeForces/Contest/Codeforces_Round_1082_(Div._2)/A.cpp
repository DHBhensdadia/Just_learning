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
    int x, y;
    cin >> x >> y;

    if (y < 0){
        x = x + (y * 4);
    }else if (y > 0){
        x = x - (y * 2);
    }

    if (x % 3 == 0 && x >= 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}