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
 
    int n,m;
    cin >> n >> m;

    int current_stage = 0;
    int current_time = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int required_stage;
        int given_time;
        cin >> given_time >> required_stage;

        int duration = given_time - current_time;
 
        if (current_stage == required_stage) {
            ans += (duration / 2) * 2;
        }else {
            ans += 1;
            duration--;
            ans += (duration / 2) * 2;
        }

        current_stage = required_stage;
        current_time = given_time;
    }
    ans += m - current_time;

    cout << ans << endl;
}