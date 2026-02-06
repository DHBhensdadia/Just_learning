#include <bits/stdc++.h>

using namespace std;

int main(){
    int n_t;
    cin >> n_t;

    while(n_t--){
        int x, y;
        cin >> x >> y;

        if (y > x){
            cout << 2 << endl;
        }else{
            if ((y>1) && (x >= y + 2)){
                cout << 3 << endl;
            }else {
                cout << -1 << endl;
            }
        }

    }

    return 0;
}