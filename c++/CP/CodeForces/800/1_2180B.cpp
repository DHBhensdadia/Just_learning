#include <bits/stdc++.h>
using namespace std;

void solution(void);

int main(){
    int n_t;
    cin >> n_t;

    while(n_t--){
        solution();
    }
}

void solution(void){
    int n;
    cin >> n;

    string main;
    do{
        string temp;
        cin >> temp;
        main = min(temp + main, main + temp);
    }while(--n);

    cout << main << endl;
}