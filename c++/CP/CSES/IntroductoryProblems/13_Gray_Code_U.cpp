#include <bits/stdc++.h>

using namespace std;

void add(string &bit);

int main(){
    int n;
    cin >> n;

    string bit;
    for (int i = 0; i < n; i++){
        bit.push_back('0');
    }
    cout << bit << endl;

    int times = pow(2, n);
    for (int i = 1; i < times; i++){
        add(bit);
        cout << bit << endl;
    }
}

void add(string &bit){
    
}