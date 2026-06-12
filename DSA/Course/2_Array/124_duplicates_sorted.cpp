// Finding Duplicates in a sorted array (Counting included)

#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[] = {3, 4, 5, 8, 8, 8, 9, 10, 13, 24 ,24, 24, 24, 25, 28};
    int n = sizeof(arr) /sizeof(int);

    for (int i = 0, j = 1; j < n; ){
        if (arr[i] == arr[j]) {
            cout << arr[i];
            int count = 1;
            while (arr[i] == arr[j] && j < n){
                count++;
                j++;
            } 
            cout << " : " << count << endl;
            i = j - 1;
        }
        else  {
            i++;
            j++;
        }
    }

    return 0;
}

