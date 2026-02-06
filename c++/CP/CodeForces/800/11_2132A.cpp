#include <bits/stdc++.h>

using namespace std;

int main (){
    int nt;
    cin >> nt;

    while (nt--){
        int a, o;
        string ans, hw, ope;
        cin >> a >> ans >> o >> hw >> ope;

        for (int i = 0; i < o; i++){
            if (ope[i] == 'D'){
                ans.push_back(hw[i]);
            }else {
                ans.insert(ans.begin(), hw[i]);

            }
        }

        cout << ans << endl;
    }

    return 0;
}