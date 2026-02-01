#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    int len = s.length();
    sort(s.begin(), s.end());
    
    string ans;
    string ans2;
    int count = 0;
    char diff ;
    for (int i = 0; i < len; i+=2 ){
        if (s[i] == s[i+1]){
            ans.push_back(s[i]);
            ans2.push_back(s[i]);   
        }else{
            diff = s[i];
            count++;
            i--;
        }
    }

    if(count > 1){
        cout << "NO SOLUTION";
        return 0;
    }else if (count == 1){
        reverse(ans2.begin(), ans2.end());
        ans.push_back(diff);
        ans = ans + ans2;

        cout << ans;
        return 0;
    }else {
        reverse(ans2.begin(), ans2.end());
        ans = ans + ans2;

        cout << ans;
        return 0;
    } 

}