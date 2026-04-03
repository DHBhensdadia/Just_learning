#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    for(int i = 0; i < n; i++){
        cout << 0;
    }
    cout << endl;

    for (int i = 1; i < pow(2, n); i++){
        int de = i;
        string binary;
        while (de != 0){
            binary.push_back(de%2 + '0');
            de /= 2;
        } 

        reverse(binary.begin(), binary.end());

        int sufix0 = n - binary.size();
        for(int j = 0; j < sufix0; j++){
            cout << 0;
        }

        cout << binary[0];
        int gray_size = binary.size();
        for(int j = 1; j < gray_size ;j++){
            cout << ((binary[j - 1] - '0') ^ (binary[j] - '0'));
        }
        cout << endl;

    }

}

