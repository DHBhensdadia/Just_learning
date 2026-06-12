// Finding missing elements in a sorted array

#include <bits/stdc++.h>

using namespace std;

void find(int * arr, int size) {

    int diff = arr[0];

    for(int i = 1; i < size; i++) {
        if (arr[i] - i != diff){
            while (diff != arr[i] - i) {
                cout << diff + i << endl;
                diff++;
            }
        }
    }


}

int main () {
    
    int arr[] = {6,7,8,9,11,12,15,16,17,18,25};

    find(arr, 11);
}