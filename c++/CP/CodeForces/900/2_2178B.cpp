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
    string str;
    cin >> str;

    int n = str.size();

    int i_first_s = -1;
    int i_second_s = -1;
    int ans{0};

    // initial handal
    if(str[0] == 's'){
        i_second_s = 0;
    }else if(str.find("s") == string::npos){
        cout << n/2 + 1 << endl;
        return;
    }else if(str[0] == 'u'){
        i_second_s = str.find("s");
        if (i_second_s & 1){
            ans += i_second_s/2 + 1;
        }else {
            ans += i_second_s/2;
        }
    }       

    // loop untill end of string
    while(str.find("s", i_second_s + 1) != string::npos){
        i_first_s = i_second_s;
        i_second_s = str.find("s", i_second_s + 1);
        int u_btw = i_second_s - i_first_s - 1;
        ans += u_btw / 2;
    }

    // final handal
    int u_left = n - i_second_s - 1;
    if (u_left & 1){
        ans += u_left / 2 + 1;
    }else {
        ans += u_left / 2;
    }

    // print and return
    cout << ans << endl;

}