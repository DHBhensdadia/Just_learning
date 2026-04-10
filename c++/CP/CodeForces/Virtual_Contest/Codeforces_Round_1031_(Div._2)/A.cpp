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
    
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;

    int ans = 0;

    if (x < y){
        {
            if (k >= a){
                int pos = (k - a)/ x;
                k -= pos * x;
                ans = ans + pos;
                if(k >= a){
                    k -= x;
                    ans++;
                } 
            }
        }
        {
            if (k >= b){
                int pos = (k - b)/ y;
                k -= pos * y;
                ans = ans + pos;
                if(k >= b){
                    k -= y;
                    ans++;
                }
            }
        }
    }else {
        {
            if (k >= b){
                int pos = (k - b)/ y;
                k -= pos * y;
                ans = ans + pos;
                if(k >= b){
                    k -= y;
                    ans++;
                }
            }
        }
        {
            if (k >= a){
                int pos = (k - a)/ x;
                k -= pos * x;
                ans = ans + pos;
                if(k >= a){
                    k -= x;
                    ans++;
                } 
            }
        }
    }

    cout << ans << endl;

}