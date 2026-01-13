#include <iostream>
using namespace std;
#define ll long long

ll solution ();
ll diagonal(ll);

int main(){
    int n_t;
    cin >> n_t;
    
    while (n_t--){
        cout << solution() << endl;
    }
    
    return 0;
}

ll solution (){
    ll i ,j;
    cin >> i >> j;
    i--, j--;
    
    if ( i == j){
        return diagonal(i);
    }else if (i < j){
        if (j&1){
            return diagonal(j) - (j - i);
        }else {
            return diagonal(j) + (j - i);
        }
    }else {
        if (i&1){
            return diagonal(i) + (i - j);
        }else {
            return diagonal(i) - (i - j);
        } 
    }
    
}

ll diagonal(ll max){
    ll dia{1};
    
    // for (int i = 0; i <= max; i++ ){
    //     dia += 2*i;
    // }

    dia += (max)*(max + 1);
    
    return dia;
}
