#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nt; cin >> nt;
    set<int> s;
    while (nt--){
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    cout << s.size() << endl;

}

