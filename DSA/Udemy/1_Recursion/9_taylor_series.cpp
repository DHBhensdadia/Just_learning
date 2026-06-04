// This code contains taylors series for exponential function up to first 15 terms


#include <iostream> 
#include <iomanip>
#define T 15
#define ld long double

using namespace std;

ld fac(int n){

    if(n < 0){
        return 0;
    }else if (n == 0){
        return 1;
    }else {
        ld ans = fac(n - 1) * n; 
        return ans;
    }

}

ld my_pow(ld n,int m){
    
    if (m == 0){
        return 1;
    }else if (m & 1){
        ld ans = n * my_pow(n * n, m / 2);
        return ans;
    }else {
        ld ans = my_pow(n * n, m/2);
        return ans;
    }
}

ld taylor(int t, ld x){
    if (t == 0){
        return 1;
    }else {
        ld ans = taylor(t-1, x) + (my_pow(x, t) / fac(t));
        return ans;
    }
}

int main(){

    cout << fixed << setprecision(6);
    cout << taylor(T, 7.0) << endl;

    return 0;
}
