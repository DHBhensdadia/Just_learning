#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;

    while (n--){
        string str;
        cin >> str;
        while((str.find("FFT") != -1)|| (str.find("NTT") != -1)){
            int id1 = str.find("FFT");
            int id2 = str.find("NTT");
            if (id1 != -1){
                char temp = str[id1 + 1];
                str[id1 + 1] = str[id1 +2];
                str[id1 + 2] = temp;
            } 
            if (id2 != -1){
                char temp = str[id2];
                str[id2] = str[id2 + 1];
                str[id2 + 1] = temp;
            }  
        }

        cout << str << endl;
    }

    return 0;
}