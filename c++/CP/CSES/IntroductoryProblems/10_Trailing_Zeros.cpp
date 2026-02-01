#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;

    int ans = 0;
    while (n > 1){
        ans += (n /= 5);
    }

    cout << ans;
    return 0;
}