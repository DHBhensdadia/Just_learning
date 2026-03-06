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

    vector<int> v(n);
    for (auto &i : v){
        cin >> i;
    }
    sort(v.begin(), v.end());

    int current_strik{0};
    int max_strik{0};

    for (int i = 1; i < n; i++){
        if(v[i-1] + 1 == v[i]){
            current_strik++;
        }else if (v[i-1] == v[i]){

        }else { 
            current_strik++;
            if (current_strik > max_strik){
                max_strik = current_strik;
            }
            current_strik = 0;
        }
    }

    current_strik++;
    if (current_strik > max_strik){
        max_strik = current_strik;
    }

    cout << max_strik << endl;

}