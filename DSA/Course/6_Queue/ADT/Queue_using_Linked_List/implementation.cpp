#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T>* next;

    Node() : next(nullptr) {}
    Node(T d) : data(d), next(nullptr) {}
};

template<typename T>
class Queue {
    Node<T>* front;
    Node<T>* rear;

public:
    // constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // destructor to free memory
    ~Queue() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Operations on abstract data type

    // 1. Enqueue (For insertion)
    void enqueue(T val) {
        Node<T>* t = new Node<T>(val);

        if(t == nullptr) {
            cout << "Queue is Full (Heap Exhausted)" << endl;
        } else {
            if(front == nullptr) {
                front = rear = t;
            } else {
                rear->next = t;
                rear = t;
            }
        }
    }

    // 2. Dequeue (For deletion)
    T dequeue() {
        if(front == nullptr) {
            cout << "Queue is Empty" << endl;
            return T();
        } else {
            Node<T>* p = front;
            front = front->next;
            T val = p->data;
            delete p;

            // If the queue becomes empty after deletion, update rear as well
            if(front == nullptr) {
                rear = nullptr;
            }
            return val;
        }
    }

    // 3. Display
    void display() {
        if(front == nullptr) {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node<T>* p = front;
        cout << "Elements are :";
        while(p != nullptr) {
            cout << " " << p->data;
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q;

    // 1. Enqueue
    cout << endl << "1." << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << "Enqueued 5 elements." << endl;

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

    // 4. Test emptying the queue completely
    cout << endl << "4." << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "Dequeued remaining 3 elements." << endl;
    q.display();

    // 5. Dequeue on empty
    cout << endl << "5." << endl;
    q.dequeue();

    return 0;
}
