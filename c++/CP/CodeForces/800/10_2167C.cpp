#include <bits/stdc++.h>

using namespace std;

int main (){
    int n_t;
    cin >> n_t;

    while (n_t--){
        int n;
        cin >> n;

        vector<int> v;
        int flagO{0}, flagE{0};
        for (int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            v.emplace_back(temp);

            if (flagO == 0 && temp&1){
                flagO++;
            }

            if (flagE == 0 && !(temp&1)){
                flagE++;
            }

        }

        if (flagE && flagO){
            sort(v.begin(), v.end());
        }
        for (auto it : v){
            cout << it << ' ';
        }
        cout << endl;

    }

}