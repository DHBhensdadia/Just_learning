#include <bits/stdc++.h>

using namespace std;

void solution(void){
    int n;
    cin >> n;
    string str;
    cin >> str;

    for (int i = 1; i < n - 1; i++){
        int temp_count{0};
        for (auto it : str){
            if (str[i] == it){
                temp_count++;
            }
            if(temp_count == 2){
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

int main (){
   int n_t = 0;
   cin >> n_t;

   while (n_t--){
    solution();
   }
}