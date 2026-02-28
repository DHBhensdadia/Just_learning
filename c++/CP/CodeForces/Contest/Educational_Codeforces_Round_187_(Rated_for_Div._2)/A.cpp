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
    int n, m, d;

    cin >> n >> m >> d;

    int tsize = d/m + 1;

    int ntower;
    if (n % tsize == 0){
        ntower = n/tsize;
    }else {
        ntower = n/tsize + 1;
    }

    cout << ntower << endl;
}