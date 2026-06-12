// Hash table/ Bitset Method      (Unsorted)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int l = 1;
    int h = 12;

    vector<int> H(h + 1, 0);

    for (int i = 0; i < n; i++) {
        H[arr[i]]++;
    }

    for (int i = l; i <= h; i++) {
        if (H[i] == 0) {
            cout << i << endl;
        }
    }
    
    return 0;
}