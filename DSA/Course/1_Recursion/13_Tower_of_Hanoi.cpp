#include <bits/stdc++.h>
using namespace std;

void TOH(int n, int A, int B, int C);

int main () {
    TOH(5, 1, 2, 3);
    return 0;
}

void TOH(int n, int A, int B, int C) {

    // static variable
    static int step = 0;

    // procedure
    if (n > 0) {
        TOH(n - 1, A, C, B);
        cout << "Step : " << ++step << " -> Move top disc from " << A << " to " << C << endl;
        TOH(n - 1, B, A, C);
    }
    
}