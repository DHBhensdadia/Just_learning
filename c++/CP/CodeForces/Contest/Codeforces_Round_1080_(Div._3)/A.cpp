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

    sort(v.begin(), v.end());
    if (binary_search(v.begin(), v.end(), 67)){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
}