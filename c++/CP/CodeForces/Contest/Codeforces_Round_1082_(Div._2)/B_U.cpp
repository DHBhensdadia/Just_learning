#include <bits/stdc++.h>
using namespace std;

bool solution(void);
bool check_ab(string str);
string adder(string str){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nt; cin >> nt;
    while (nt--){
        if (solution() == true){
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }

}

bool solution(void){
    string inp;
    int size = inp.length();
    cin >> inp;

    bool flag = false;
    for (int i = 0; i < size; i++){
        if(inp[i] == '?'){
            flag = true;
            break;
        }
    }

    if (!flag){
        return check_ab(inp);
    }

    


}

bool check_ab(string str){
    int size = str.size();
    string ab;
    for(int i = 0; i < size; i++){
        if (i&1){
            ab.push_back('b');
        }else {
            ab.push_back('a');
        }
    }

    auto start = ab.begin();
    auto end = ab.end() - 1;

    for(int i = 0; i < size; i++){

        if(str[i] == *end){
            end--;
        }else if (str[i] == *start){
            start++;
        }else{
            return false;
        }

        if (start == end){
            break;
        }
    }

    return true;
}