#include <bits/stdc++.h>

using namespace std;

int main (){
    string name, temp;

    cin >> name >> temp;
    name += temp;

    cin >> temp;


    map<char, int> guest, pile;
    for (char a : name){
        guest[a]++;
    }
    for (char a : temp){
        pile[a]++;
    }


    if (guest == pile){
        cout << "YES";
    }else {
        cout << "NO";
    }
}