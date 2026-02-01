#include <bits/stdc++.h>
using namespace std;

void sol(void){
    int n;
    cin >> n;

    int max = 0;
    int count{0};
    while(n--){
        int temp;
        cin >> temp;

        if (temp >= max){
            max = temp;
        }else {
            count++;
        }
    }

    cout << count << endl;

}

int main(){
    int n_t;
    cin >> n_t;

    while(n_t--){
        sol();
    }

    return 0;
}