#include <bits/stdc++.h>
using namespace std;

template<typename T>
class CircularQueue {
    int front;
    int rear;
    int size;
    T *arr;

public :
    // constructors
    CircularQueue () {
        size = 10;
        front = 0;
        rear = 0;
        arr = new T[size];
    }
    CircularQueue (int size) {
        this->size = size;
        front = 0;
        rear = 0;
        arr = new T[this->size];
    }
    
    // destructor
    ~CircularQueue() {
        delete[] arr;
    }

    // Operations on abstract data type

    // 1. Enqueue (For insertion)
    void enqueue (T val) {
        if((rear + 1) % size == front) {
            cout << "Queue is Full" << endl;
        } else {
            rear = (rear + 1) % size;
            arr[rear] = val;
        }
    }

    // 2. Dequeue (For deletion)
    T dequeue () {
        if(front == rear) {
            cout << "Queue is Empty" << endl;
            return T();
        } else {
            front = (front + 1) % size;
            return arr[front];
        }
    }

    // 3. Display
    void display () {
        if (front == rear) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Elements are :";
        int i = (front + 1) % size;
        do {
            cout << " " << arr[i];
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
};

int main () {
    // Array of size 6 can store up to 5 elements in this circular queue implementation
    CircularQueue<int> q(6);

    // 1. Enqueue
    cout << endl << "1." << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << "Enqueued 5 elements." << endl;
    q.enqueue(60);                                          // Should print full

    // 2. Display
    cout << endl << "2." << endl;
    q.display();

    // 3. Dequeue
    cout << endl << "3." << endl;
    int x = q.dequeue();
    cout << x << " is deleted from queue" << endl;
    q.display();
    
    int y = q.dequeue();
    cout << y << " is deleted from queue" << endl;
    q.display();

    // 4. Enqueue again to prove circular behavior
    cout << endl << "4." << endl;
    q.enqueue(60);
    q.enqueue(70);
    cout << "Enqueued 60 and 70 circularly." << endl;
    q.display();

    return 0;
}
