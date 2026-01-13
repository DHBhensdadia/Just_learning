#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    
    for (int i = 0; i < n - 1; i++){
        int temp;
        cin >> temp;
        arr[temp-1]++;
    }

    for (int i = 0; i < n; i++){
        if(!arr[i]){
            cout << i + 1;
            break;
        }
    }

    return 0;
}