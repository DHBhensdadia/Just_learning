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
    
    int n;
    cin >> n;

    int urequired = (n - 1)*2 + 1;
    int traker = urequired + 2;
    int lrequired = (n - 1) / 2;
    int flag = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if ((float)i < n/2.0){
            traker -= 2;
        }else if((float)i == n/2.0) {

        }else {
            traker += 2;
        }
        if (temp < traker){
            flag = 1;
        }
    }

    if (flag == 1){
        cout << "NO" << endl;
    }else {
        cout << "YES" << endl;
    }

}