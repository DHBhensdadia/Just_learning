#include <bits/stdc++.h>
using namespace std;

void solution(void);

int main (){
    int n;
    cin >> n;

    while (n--){
        solution();
    }

}

void solution(void){
    int a, b;
    cin >> a >> b;

    if (a == b){

        if(a%3 == 0){
            cout <<"YES" << endl;
        }else {
            cout << "NO" << endl;
        }
        return;

    }else if (a < b){

        int diff = b - a;
        if (a >= diff && b >= 2*diff){
            if((a-diff) == (b-(2*diff))){
                if ((a-diff)%3 == 0){
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
        return;

    }else {
        int diff = a - b;
        if (a >= 2*diff && b >= diff){
            if((b-diff) == (a-(2*diff))){
                if ((b-diff)%3 == 0){
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
        return;
    }

}