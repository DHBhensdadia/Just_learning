// Implemented DEQ using LL

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() : next(nullptr), prev(nullptr) {}
    Node(T d) : data(d), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DEQ {
    Node<T>* front;
    Node<T>* rear;

public:
    DEQ() {
        front = nullptr;
        rear = nullptr;
    }

    ~DEQ() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // 1. insertFront
    void insertFront(T val) {
        Node<T>* t = new Node<T>(val);
        if (t == nullptr) {
            cout << "Queue is Full (Heap Exhausted)" << endl;
        } else {
            if (front == nullptr) {
                front = rear = t;
            } else {
                t->next = front;
                front->prev = t;
                front = t;
            }
        }
    }

    // 2. insertRear
    void insertRear(T val) {
        Node<T>* t = new Node<T>(val);
        if (t == nullptr) {
            cout << "Queue is Full (Heap Exhausted)" << endl;
        } else {
            if (front == nullptr) {
                front = rear = t;
            } else {
                rear->next = t;
                t->prev = rear;
                rear = t;
            }
        }
    }

    // 3. deleteFront
    T deleteFront() {
        if (front == nullptr) {
            cout << "Queue is Empty" << endl;
            return T();
        } else {
            Node<T>* p = front;
            front = front->next;
            if (front != nullptr) {
                front->prev = nullptr;
            } else {
                rear = nullptr; // Queue became empty
            }
            T val = p->data;
            delete p;
            return val;
        }
    }

    // 4. deleteRear
    T deleteRear() {
        if (rear == nullptr) {
            cout << "Queue is Empty" << endl;
            return T();
        } else {
            Node<T>* p = rear;
            rear = rear->prev;
            if (rear != nullptr) {
                rear->next = nullptr;
            } else {
                front = nullptr; // Queue became empty
            }
            T val = p->data;
            delete p;
            return val;
        }
    }

    // 5. getFront
    T getFront() {
        if (front == nullptr) {
            cout << "Queue is Empty" << endl;
            return T();
        }
        return front->data;
    }

    // 6. getRear
    T getRear() {
        if (rear == nullptr) {
            cout << "Queue is Empty" << endl;
            return T();
        }
        return rear->data;
    }

    // 7. display
    void display() {
        if (front == nullptr) {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node<T>* p = front;
        cout << "Elements are :";
        while (p != nullptr) {
            cout << " " << p->data;
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    DEQ<int> q;

    // 1. insertRear
    cout << endl << "1." << endl;
    q.insertRear(10);
    q.insertRear(20);
    cout << "Inserted 10 and 20 at rear." << endl;
    q.display();

    // 2. insertFront
    cout << endl << "2." << endl;
    q.insertFront(5);
    q.insertFront(1);
    cout << "Inserted 5 and 1 at front." << endl;
    q.display();

    // 3. getFront and getRear
    cout << endl << "3." << endl;
    cout << "Front element is: " << q.getFront() << endl;
    cout << "Rear element is: " << q.getRear() << endl;

    // 4. deleteFront
    cout << endl << "4." << endl;
    int x = q.deleteFront();
    cout << x << " is deleted from front" << endl;
    q.display();

    // 5. deleteRear
    cout << endl << "5." << endl;
    int y = q.deleteRear();
    cout << y << " is deleted from rear" << endl;
    q.display();

    // 6. Emptying DEQ
    cout << endl << "6." << endl;
    q.deleteFront();
    q.deleteRear();
    cout << "Deleted remaining elements." << endl;
    q.display();

    return 0;
}
