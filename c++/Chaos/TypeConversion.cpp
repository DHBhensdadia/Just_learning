#include <bits/stdc++.h>

using namespace std;

class Number {
    int num;
public:
    Number(int num) {
        cout << "N Constructor Called\n";
        this->num = num;
    }
    int get_num() {
        return num;
    }
    ~Number(){
        cout<<"N Destructor Called"<<endl;
    }

    friend ostream &operator<<(ostream &strm, Number &n);
};
ostream &operator<<(ostream &strm, Number &n) {
    strm << "num is: " << n.num ;
    return strm;
}


class Fnumber {
    float fnum;
public:
    Fnumber(float fnum) {
        cout << "FN Constructor Called - 1st\n";
        this->fnum = fnum;
    }

    Fnumber(Number n) {
        cout << "FN Constructor Called - 2nd\n";
        this->fnum = n.get_num();
    }

    operator Number() {
        cout << "FN Conversion Fuction Called\n";
        return Number(int(fnum));
    }
    ~Fnumber(){
        cout<<"FN Destructor Called" <<endl;
    }
    friend ostream &operator<<(ostream &strm, Fnumber &fn);
};
ostream &operator<<(ostream &strm, Fnumber &fn) {
    strm << "num is: " << fn.fnum;
    return strm;
}


int main() {
    Number n = 10;
    cout << n << endl;;
    Fnumber fn = 7.7f;
    cout << fn << endl;
    n = fn;
    cout << n << endl;
    fn = n;
    cout << fn << endl;
    return 0;
}
