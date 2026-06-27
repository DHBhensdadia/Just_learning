#include <bits/stdc++.h>
using namespace std;

// Base Queue class to manage individual priority levels
template<typename T>
class Queue {
    int front;
    int rear;
    int size;
    T *arr;

public :
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
    ~Queue() {
        delete[] arr;
    }

    void enqueue (T val) {
        if(rear == size - 1) {
            cout << "Queue is Full" << endl;
        } else {
            rear++;
            arr[rear] = val;
        }
    }

    T dequeue () {
        if(front == rear) {
            return T(); // Empty
        } else {
            front++;
            return arr[front];
        }
    }

    bool isEmpty() {
        return front == rear;
    }

    void display () {
        if (front == rear) {
            cout << "(Empty)";
        }
        for(int i = front + 1; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Priority Queue wrapper containing 3 distinct priority levels
template<typename T>
class PriorityQueue {
    Queue<T> q1; // Priority 1 (Highest)
    Queue<T> q2; // Priority 2
    Queue<T> q3; // Priority 3

public:
    PriorityQueue() : q1(10), q2(10), q3(10) {}

    // 1. Insert with priority
    void insert(T val, int pr) {
        if(pr == 1) {
            q1.enqueue(val);
        } else if(pr == 2) {
            q2.enqueue(val);
        } else if(pr == 3) {
            q3.enqueue(val);
        } else {
            cout << "Invalid Priority" << endl;
        }
    }

    // 2. Delete (Highest priority first)
    T dequeue() {
        if(!q1.isEmpty()) {
            return q1.dequeue();
        } else if(!q2.isEmpty()) {
            return q2.dequeue();
        } else if(!q3.isEmpty()) {
            return q3.dequeue();
        } else {
            cout << "Priority Queue is Empty" << endl;
            return T();
        }
    }

    // 3. Display all queues
    void display() {
        cout << "Priority 1 Queue: ";
        q1.display();
        cout << "Priority 2 Queue: ";
        q2.display();
        cout << "Priority 3 Queue: ";
        q3.display();
    }
};

int main() {
    PriorityQueue<char> pq;

    cout << "--- 1. Inserting Elements ---" << endl;
    pq.insert('a', 1);
    pq.insert('b', 1);
    pq.insert('c', 2);
    pq.insert('d', 3);
    pq.insert('e', 2);
    pq.insert('f', 1);
    pq.insert('g', 2);
    pq.insert('h', 3);
    pq.insert('i', 2);
    pq.insert('j', 2);
    
    pq.display();

    cout << "\n--- 2. Deleting 4 Elements ---" << endl;
    cout << pq.dequeue() << " is deleted" << endl;
    cout << pq.dequeue() << " is deleted" << endl;
    cout << pq.dequeue() << " is deleted" << endl;
    cout << pq.dequeue() << " is deleted" << endl;
    
    cout << endl;
    pq.display();

    cout << "\n--- 3. Inserting Elements Again ---" << endl;
    pq.insert('z', 2);
    pq.insert('w', 1);
    
    pq.display();

    return 0;
}
