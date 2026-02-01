#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
    int temp = sqrt(n);
    if (n < 2){
        return false;
    }else if (n == 2){
        return true;
    }
    for (int i = 2; i <= temp; i++){
        if (n%i == 0){
            return false;
        }
    }

    return true;
}


int main(){

    int a, b;
    cin >> a >> b;

    if (a >= b){
        return -1;
    }

    if ( !is_prime(a) || !is_prime(b)){
        cout << "NO" << endl;
        return 0;
    }

    int diff = b - a - 1;
   
    for (int i = 0; i < diff; i++){
        if (is_prime(++a)){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}