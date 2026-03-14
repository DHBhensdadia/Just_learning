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

    unordered_map<int,int> cnt;
    cnt.reserve(n*2);

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (temp < k){
            cnt[temp]++;         
        }
    }

    int score = 0;

    for (auto it = cnt.begin(); it != cnt.end(); ++it){
        int x = it->first;
        int &cx = it->second;
        if (cx == 0) continue;  

        int need = k - x;
        if (need == x){
            score += cx / 2;
            cx = 0;
        } else {
            auto it2 = cnt.find(need);
            if (it2 != cnt.end() && it2->second > 0){
                int take = min(cx, it2->second);
                score += take;
                cx -= take;
                it2->second -= take;
            }
        }
    }

    cout << score << '\n';
}