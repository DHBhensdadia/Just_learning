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
    int max, min;
    cin >> max;
    min = max;
    
    for(int i = 1; i < n; i ++){
        int temp;
        cin >> temp;
        if (temp > max) {
            max = temp;
        }

        if(temp < min ) {
            min = temp;
        }
    }
    
    cout << max + 1 - min << endl;

}
