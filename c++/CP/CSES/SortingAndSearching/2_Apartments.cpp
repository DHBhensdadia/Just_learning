#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tapli, tapar, k;
    cin >> tapli >> tapar >> k;

    int aplicant_count = 0;
    int apartment_count = 0;
    int ans = 0;

    vector<int> vapli, vapar;
    for (int i = 0; i < tapli; i++){
        int temp;
        cin >> temp;
        vapli.push_back(temp);
    }
    for (int i = 0; i < tapar; i++){
        int temp;
        cin >> temp;
        vapar.push_back(temp);
    }

    sort(vapli.begin(), vapli.end());
    sort(vapar.begin(), vapar.end());

    while(aplicant_count < tapli && apartment_count < tapar){
        
        if (vapli[aplicant_count] - k > vapar[apartment_count]){
            apartment_count++;
        }else if (vapli[aplicant_count] - k <= vapar[apartment_count]  &&  vapli[aplicant_count] + k >= vapar[apartment_count]){
            ans++;
            aplicant_count++;
            apartment_count++;
        }else {
            aplicant_count++;
        }
    }

    cout << ans << endl;

}