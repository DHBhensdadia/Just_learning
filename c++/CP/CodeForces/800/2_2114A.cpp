#include <bits/stdc++.h>

using namespace std;

void solution(void);

int main (){
    int n_t;
    cin >> n_t;

    while(n_t--){
        solution();
    }

    return 0;
}

void solution(void){
    int n;
    cin >> n;

    long long in = ceil(sqrt(n));
    if (in * in != n){
        cout << "-1\n";
        return;
    }
    
    if (in == 0) {
        cout << "0 0" << endl; 
        return;
    }

    cout << 1 << " " << in - 1 << endl;
}