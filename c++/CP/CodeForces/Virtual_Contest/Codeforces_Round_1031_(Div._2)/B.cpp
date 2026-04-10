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
    
    int w, h, a, b;
    int x, y, p, q;

    cin >> w >> h >> a >> b >> x >> y >> p >> q ;

    int hod = p - (x + a);
    int ved = q - (y + b);

    if ((hod % a != 0 || ved % b != 0) && (x == p || y == q)){
        cout << "NO" << endl;
    }else if (hod % a == 0 || ved % b == 0){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }

}