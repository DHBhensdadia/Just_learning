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
 
    string s;
    cin >> s;

    vector<int> v;
    for(auto i : s){
        v.emplace_back(i - '0');
    }


    int n = v.size();
    int count = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
        auto it = min_element(v.begin(), v.end());
        if (*it + count < 10){
            if(it == v.begin()){
                flag = true;
            }
            count += *it;
            v.erase(it);
        }else{
            break;
        }
    }
    if (flag == false && count == 9){
        cout << v.size() + 1 << endl;
    }else {
        cout << v.size() << endl;
    }

    

}