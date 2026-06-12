// Finding Duplicates in Un/sorted array (Using Hash Map)

#include <bits/stdc++.h>
using namespace std;
class Array{
      int *arr;
      int size;
      int length;
    public:
    Array (int* arr, int size, int length){
        // Deep copy
        this->arr = new int[size];
        for (int i = 0; i < length; i++){
            this->arr[i] = arr[i];
        }
        this->size = size;
        this->length = length;
    }
    Array (int size, int length) {
        arr = new int[size];
        this->size = size;
        this->length = length;
    }
    ~Array() {
        delete[] arr;
    }

    // max min 
    int max() {
        int m = arr[0];
        for(int i = 1; i < length; i++){
            if(arr[i] > m) {
                m = arr[i];
            }
        }
        return m;
    }
    int min() {
        int m = arr[0];
        for(int i = 1; i < length; i++){
            if(arr[i] < m) {
                m = arr[i];
            }
        }
        return m;
    }

    void findDuplicate()
    {
      
        int h = this->max();
        int l = this->min();
        vector<int> H(h+1,0);
        for (int i = 0; i < length;i++) 
        {
            H[arr[i]]++;
        }
        for (int i = l; i < h+1;i++)
        {
            if(H[i]>1)
            {
                    cout << i << " is duplicated " << H[i] << " times" << endl;
            }
        }
        
    }

};


int main() {
    int arr[] = {1,2,8,4,3,5,8,5,1,3,7,12,13,16,3,7,13};
    int size = sizeof(arr)/ sizeof(int);

    Array a(arr, size, size);

    a.findDuplicate();
}