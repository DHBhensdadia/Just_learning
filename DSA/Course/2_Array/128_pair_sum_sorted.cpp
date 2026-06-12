// Finding a pair of elements with sum k in sorted array

#include <bits/stdc++.h>

using namespace std;

class Array {
    int *arr;
    int size;
    int length;

public:
    Array(int* input_arr, int size, int length) {
        this->size = size;
        this->length = length;
        this->arr = new int[size];
        for (int i = 0; i < length; i++) {
            this->arr[i] = input_arr[i];
        }
    }

    ~Array() {
        delete[] arr;
    }

    bool isSorted() {
        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    int max() {
        int m = arr[0];
        for (int i = 1; i < length; i++) {
            if (arr[i] > m) {
                m = arr[i];
            }
        }
        return m;
    }

    void Pair_element_Sorted(int k) {
        int i = 0;
        int j = length - 1;

        while (i < j) {
            if (arr[i] + arr[j] == k) {
                cout << arr[i] << " + " << arr[j] << " = " << k << endl;
                i++;
                j--;
            } else if (arr[i] + arr[j] < k) {
                i++;
            } else {
                j--;
            }
        }
    }

    void Pair_element_Hashing_sorted(int k) {
        int h = this->max();
        vector<int> H(h + 1, 0);

        for (int i = 0; i < length; i++) {
            int index = k - arr[i];
            if (index >= 0 && index <= h && H[index] > 0) {
                cout << arr[i] << " + " << index << " = " << k << endl;
            }
            H[arr[i]]++;
        }
    }
};

int main() {
    int predefined_arr[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    int length = sizeof(predefined_arr) / sizeof(predefined_arr[0]);
    int size = length * 2;
    int k = 10;

    Array a(predefined_arr, size, length);

    if (a.isSorted()) {
        cout << "Finding Pair Element using Simple (Two-Pointer) Method:" << endl;
        a.Pair_element_Sorted(k);

        cout << "\nFinding Pair Element using Hashing Method:" << endl;
        a.Pair_element_Hashing_sorted(k);
    } else {
        cout << "Array is not Sorted." << endl;
    }

    return 0;
}