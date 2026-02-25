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

    vector<int> v3;
    for (int i = 0; i < n/2; i++){
        v3.emplace_back(v[i]);
    }
    for (int i = n/2; i < n; i++){
        if (i & 1){
            v3.emplace_back(v[i]);
        }
    }
    sort(v3.begin(), v3.end());

    int count=0;
    for (int i = 0; i < n/2; i++){
        v[i] = v3[count++];
    }
    for (int i = n/2; i < n; i++){
        if (i & 1){
            v[i] = v3[count++];
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