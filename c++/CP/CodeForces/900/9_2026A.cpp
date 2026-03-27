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
    
    int X, Y, K;
    cin >> X >> Y >> K;

    int mini = min(X, Y);

    cout << 0 << ' ' << 0 << ' ' << mini << ' ' << mini << endl;
    cout << 0 << ' ' << mini << ' ' << mini << ' ' << 0 << endl;

}