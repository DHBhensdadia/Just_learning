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
    
    int n, k, p;

    cin >> n >> k;
    vector<int> v(n);
    for (auto & i : v){
        cin >> i;

    }
    cin >> p;

    auto start = v.begin();
    auto last = v.end() - 1;

    auto f = v.begin() + p - 1;
    auto l = f;

    int steps = 0;
    int target = *f;
    while (start != f || l != last){

        // move to same
        while (1){
            if(f != start){
                if(*f == *(f - 1)){
                    f -= 1;
                }else {
                    break;
                }
            }
            else {
                break;
            }
        }
        while (1){
            if(l != last){
                if(*l == *(l + 1)){
                    l += 1;
                }else {
                    break;
                }
            }
            else {
                break;
            }
        }

        // flip
        steps ++;
        // for (auto i = f; i <= l; i++){
        //     *i = !(*i);

        // }
        if(f != l){
            *f = !(*f);
            *l = !(*l);
        }else {
            *f = !(*f);
        }
        

    }


    if(*f == target){
        cout << steps << endl;
    }else {
        cout << steps - 1 << endl;
    }
    

}