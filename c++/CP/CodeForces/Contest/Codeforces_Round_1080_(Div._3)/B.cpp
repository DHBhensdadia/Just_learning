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
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.emplace_back(temp);
    }


    for (int i = 1; i <= n/2; i++){
        if (i & 1){
            vector<int> vt;
            for (int j = i; j <= n; j *= 2){
                vt.emplace_back(v[j - 1]);
            }
            sort(vt.begin(), vt.end());

            int count{0};
            for (int j = i; j <= n; j *= 2){
                v[j - 1] = vt[count++];
            }
        }
        
    }

    vector<int> v2(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    if (v2 == v){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }

}