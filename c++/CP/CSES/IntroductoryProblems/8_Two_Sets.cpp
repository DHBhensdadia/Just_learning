#include <bits/stdc++.h>
using namespace std;

int main(){
    int in; 
    cin >> in;

    if (in == 3){
        cout <<"YES" << endl;
        cout << "2\n1 2\n1\n3";
    }else if ((in - 3) % 4 == 0){
        cout <<"YES" << endl;

        cout << in/2 + 1 <<endl;
        cout << "1 2";  for(int i = 4; i <= in; i += 4) {cout << ' ' << i << ' ' << i + 3;}

        cout <<endl<< in/2 <<endl;
        cout << 3;  for(int i = 5; i <= in; i += 4) {cout << ' ' << i << ' ' << i + 1;}

    }else if (in % 4 == 0){
        cout <<"YES" << endl;
        cout << in/2 <<endl;
        for(int i = 1; i <= in; i += 4) {cout << i << ' ' << i + 3 << ' ';}

        cout <<endl<< in/2 << endl;
        for(int i = 2; i <= in; i += 4) {cout << i << ' ' << i + 1 << ' ';}

    }else {
        cout <<"NO";
    }

}

