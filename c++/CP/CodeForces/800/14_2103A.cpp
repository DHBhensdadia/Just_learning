#include <bits/stdc++.h>

using namespace std;

int main (){
    int nt;
    cin >> nt;

    while (nt--){
        int a;
        cin >> a;
        set<int> s;
        while (a--){
            int temp;
            cin >> temp;
            s.insert(temp);
        }
        cout << s.size() << endl;
    }
}