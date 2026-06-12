// Finding a pair of elements with sum k

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

    int max() {
        int m = arr[0];
        for (int i = 1; i < length; i++) {
            if (arr[i] > m) {
                m = arr[i];
            }
        }
        return m;
    }

    int min() {
        int m = arr[0];
        for (int i = 1; i < length; i++) {
            if (arr[i] < m) {
                m = arr[i];
            }
        }
        return m;
    }

    void Pair_element(int k) {
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                if (arr[i] + arr[j] == k) {
                    cout << arr[i] << " + " << arr[j] << " = " << k << endl;
                }
            }
        }
    }

    void Pair_element_Hashing(int k) {
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
    int predefined_arr[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int length = sizeof(predefined_arr) / sizeof(int);
    int size = length * 2;
    int k = 12;

    Array a(predefined_arr, size, length);

    cout << "Finding Pair Element using Simple Method:" << endl;
    a.Pair_element(k);

    cout << "\nFinding Pair Element using Hashing Method:" << endl;
    a.Pair_element_Hashing(k);

    return 0;
}