#include <bits/stdc++.h>

using namespace std;

void solve(){
    vector<int> v, even, odd;
    int len;
    cin >> len;
    
    for (int i = 0; i < len; i++){
        int temp;
        cin >> temp;
        v.emplace_back(temp);
    }
    for(int i = 0;i < len; i += 2){
        even.emplace_back(v.at(i));
    }
    for(int i = 1;i < len; i += 2){
        odd.emplace_back(v.at(i));
    }

    sort(v.begin(), v.end());
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int count_odd{0};
    int odd_size = odd.size();
    int count_even{0};
    int even_size = even.size();

    if (v[0] == even[0]){
        for (int i = 0; i < len; i++){
            if((i&1) && count_odd < odd_size){
                if (odd[count_odd++] != v[i]){
                    cout << "NO" << endl;
                    return;
                }
            }else if (((i&1) == 0) && count_even < even_size) {
                if (even[count_even++] != v[i]){
                    cout << "NO" << endl;
                    return;
                }
            }else {
                cout << "NO" << endl;
                return;
            }
        }
    }else {
        for (int i = 0; i < len; i++){
            if((i&1) && count_even < even_size){
                if (even[count_even++] != v[i]){
                    cout << "NO" << endl;
                    return;
                }
            }else if (((i&1) == 0) && count_odd < odd_size) {
                if (odd[count_odd++] != v[i]){
                    cout << "NO" << endl;
                    return;
                }
            }else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    

    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);          // untie cin from cout
    cout.setf(std::ios::fmtflags(0), std::ios::floatfield); // minor: avoid extra formatting work

    int n; 
    cin >> n;

    while (n--){
        solve();
    }
}