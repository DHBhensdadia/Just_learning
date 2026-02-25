#include <bits/stdc++.h>

using namespace std;

int main(){
    int ttt;
    cin >> ttt;
    while(ttt--){
        int n, h, l;
        cin >> n >> h >> l;
        
        if (n & 1){
            vector<int> v(n);
            for(auto &i : v){
                cin >> i;
            }

            auto it = max_element(v.begin(), v.end());
            if (it != v.end()) v.erase(it);

            set<int> s;
            for(auto i : v){
                s.insert(i);
            }

            int row_el{0};
            int col_el{0};

            for (auto i : s){
                if (i <= h){
                    row_el++;
                }
                if(i <= l){
                    col_el++;
                }
            }

            int diff_ele = abs(row_el - col_el);            
            
            cout << (min(row_el, col_el) + diff_ele*min(row_el, col_el)) << endl;
        }else {
            set<int> s;
            for(int i = 0; i < n; i++){
                int temp;
                cin >> temp;
                s.insert(temp);
            }

            int row_el{0};
            int col_el{0};

            for (auto i : s){
                if (i <= h){
                    row_el++;
                }
                if(i <= l){
                    col_el++;
                }
            }

            int diff_ele = (row_el > col_el ? row_el-col_el : row_el-col_el);
            
            cout << (min(row_el, col_el) + diff_ele*min(row_el, col_el)) << endl;
        }
    }
}