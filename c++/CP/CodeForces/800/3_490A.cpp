#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;

    vector<int> v;
    
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        v.emplace_back(temp);
    }

    vector<int> p, m, e;
    int count = n;
    for (int i = 0; i < n; i++){
        if (v.back() == 1 ){
            p.emplace_back(count--);
            v.pop_back();
        }else if (v.back() == 2 ){
            m.emplace_back(count--);
            v.pop_back();
        }else if (v.back() == 3 ){
            e.emplace_back(count--);
            v.pop_back();
        }
    }

    int min = p.size();
    if (m.size() < min){
        min = m.size();
    }
    if (e.size() < min){
        min = e.size();
    }

    cout << min << endl;

    for (int i = 0; i < min; i++){
        cout << p.back() << ' ' << m.back() << ' ' << e.back() << endl;
        p.pop_back();
        m.pop_back();
        e.pop_back();
    }
} 