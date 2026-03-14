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
    int n, k;
    cin >> n >> k;

     vector<int> vec; 
    vec.reserve(n);
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    int score = 0;

    for (auto it = vec.begin(); it < vec.end(); ){
        int next_num = k - *it;
        auto loc_nn = find(it + 1, vec.end(), next_num);
        if (loc_nn != vec.end()){
            vec.erase(loc_nn);
            score++;
            it = vec.erase(it);
        }else {
            it++;
        }
    }

    cout << score << endl;

}