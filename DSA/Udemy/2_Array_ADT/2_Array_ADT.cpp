#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Array {
  private :
    T *arr;
    int size = 0;
    int length = 0;

  public :
    //constructor / distructor
    Array (T* arr, int size, int length){
        // Deep copy
        this->arr = new T[size];
        for (int i = 0; i < length; i++){
            this->arr[i] = arr[i];
        }
        this->size = size;
        this->length = length;
    }
    Array (int size, int length) {
        arr = new T[size];
        this->size = size;
        this->length = length;
    }
    ~Array() {
        delete[] arr;
    }

    //Display
    void display(){
        cout << "Elements are :";
        for(int i = 0; i < length; i++){
            cout << ' ' << arr[i];
        }
        cout << endl;
    }

    //Add, Append at last
    void append(T val) {
        if(length < size){
            arr[length] = val;
            lenght++;
        }
    }

    // swap
    void swap_(int i1, int i2){
        if (i1 < length && i2 < length){
            T temp = arr[i1];
            arr[i1] = arr[i2];
            arr[i2] = temp;
        }
    }

    //Insert/Delete
    void insert(int index, T val){
        if (length == size) return;

        if(index < length){
            for(int i = length; i != index; i--){
                arr[i] = arr[i -1];
            }
            arr[index] = val; 
            length++;
        }
    }
    void delete_(int index) {
        if (index < length){
            for (int i = index; i < length - 1; i++){
                arr[i] = arr[i + 1];
            }
            length--;
        }

    }

    // search algorithems
    int linearSearch(T val) {
        for (int i = 0; i < length; i++){
            if(arr[i] == val) {
                if(i != 0){
                    this->swap_(i, i-1);
                }
                return i;
            }
        }
        return -1;
    }
    int binarySearch(T val) {
        int l = 0;
        int h = length - 1;

        while (l <= h) {
            int mid = (h + l)/2;

            if (arr[mid] == val){
                return mid;
            }else if (val < arr[mid]) {
                h = mid - 1;
            }else {
                l = mid + 1;
            }
        }

        return -1;
    }
    int rBinarySearch(T val, int l, int h) {
        if(l > h) return -1;

        int mid = (h + l) / 2;
        if (arr[mid] == val) {
            return mid;
        } else if (val < arr[mid]) {
            return rBinarySearch(val, l, mid - 1);
        } else {
            return rBinarySearch(val, l + 1, mid);
        }
    }


    // for excessing elements get, set
    T& operator[](int index) {
        return arr[index];
    }

    // max, min
    T max() {
        int m = arr[0];
        for(int i = 1; i < length; i++){
            if(arr[i] > m) {
                m = arr[i];
            }
        }
        return m;
    }
    T min() {
        int m = arr[0];
        for(int i = 1; i < length; i++){
            if(arr[i] < m) {
                m = arr[i];
            }
        }
        return m;
    }

    // sum, average
    T sum(){
        T total;
        for(int i = 0; i < length; i++){
            total += arr[i];
        }
        return total;
    }
    T average(){
        T total = sum();
        return total/length;
    }

    // reverse
    void reverse() {
        int i = 0;
        int j = length - 1;

        for ( ; i < j; i++, j--) {
            this->swap_(i, j);
        }
    }

    // rotate / shift
    void leftShift() {
        if (length <= 0) return;
        
        for (int i = 0; i < length - 1; i++) {
            arr[i] = arr[i + 1];
        }
        
    }
    void rightShift() {
        if (length <= 0) return;
        
        for (int i = length - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
    }
    void leftRotate() {
        if (length <= 1) return;
        
        T temp = arr[0];
        for (int i = 0; i < length - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = temp;
    }
   void rightRotate() {
        if (length <= 1) return;
        
        T temp = arr[length - 1];
        for (int i = length - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
    
    // check if array is sorted
    bool isSorted() {
        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }


    //Insert
    void insertInSorted(T val) {
        if(length < size) {
            int i = length - 1;
            while(i >= 0 && arr[i] > val) { 
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = val;
            length++;
        }
    }

    // Arrenge -ve aside
    void arrengeNegative() {
        int i = 0; 
        int j= length -1;

        while (i < j) {
            while (arr[i] < 0 && i < j) {
                i++;
            }
            while (arr[j] >= 0 && i < j) {
                j--;
            }

            if (i < j && arr[i] > 0 && arr[j] < 0) {
                this->swap_(i, j);
            }
        }
    }

    Array Merge(Array& B) {
        Array C(size + B.size, length + B.length); 
        int i = 0, j = 0, k = 0;
        
        while (i < length && j < B.length) {
            if (this->arr[i] < B.arr[j]) {
                C.arr[k++] = arr[i++];
            } else {
                C.arr[k++] = B.arr[j++];
            }
        }
        for (; i < length; i++) {
            C.arr[k++] = arr[i];
        }
        for (; j < B.length; j++) {
            C.arr[k++] = B.arr[j];
        }
        return C;
    }

};