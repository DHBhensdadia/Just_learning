// two pointer approach :
// 1. front stays at address before last element for deletion
// 2. rear stays at first element for insertion

// time complexity :
// insertion -> O(1)
// deletion -> O(2)


#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Queue {
    int front;
    int rear;
    int size;
    T *arr;

public :
    // constructors
    Queue () {
        size = 10;
        front = -1;
        rear = -1;
        arr = new T[size];
    }
    Queue (int size) {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new T[this->size];
    }

    // destructor
    ~Queue() {
        delete[] arr;
    }

    // Operations on abstract data type

    // 1. Enqueue (For insertion)
    void enqueue (T val) {
        if(rear == size - 1) {
            cout << "Queue is Full" << endl;
        } else {
            rear++;
            arr[rear] = val;
        }
    }

    // 2. Dequeue (For deletion)
    T dequeue () {
        if(front == rear) {
            cout << "Queue is Empty" << endl;
            return T();
        } else {
            front++;
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
        for(int i = front + 1; i <= rear; i++) {
            cout << " " << arr[i];
        }
        cout << endl;
    }
};

int main () {
    Queue<int> q(5);

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

    return 0;
}
