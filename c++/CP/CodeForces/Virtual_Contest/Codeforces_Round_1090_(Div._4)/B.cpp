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

    vector<int> v(7);
    for(auto & c : v){
        cin >> c;
    }

    auto it = max_element(v.begin(), v.end());

    int sum=0; 
    for(int i = 0; i < 7; i++){
        sum += v[i];
    }

    cout << (sum*(-1))+(2* v.at(it - v.begin())) << endl;
}
