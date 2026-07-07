// following program contains implementation of queue using two pointers


#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Queue {
    stack<T> stack_in;
    int si_size;
    stack<T> stack_out;
    int so_size;

public :
    // constructor
    Queue () : si_size(0), so_size(0) {}

    // destructor
    ~Queue () {
        while (si_size != 0) {
            si_size--;
            stack_in.pop();
        }

        while (so_size != 0) {
            so_size--;
            stack_out.pop();
        }
    }


    // operations on abstract data type

    // 1. Enqueue
    void enqueue (T val) {
        si_size++;
        stack_in.push(val);
    }

    // 2. Dequeue
    T dequeue () {
        if(so_size > 0) {
            T val = stack_out.top();
            so_size--;
            stack_out.pop();
            return val;
        }
        else if (si_size > 0) {
            while(si_size != 0) {
                stack_out.push(stack_in.top());
                stack_in.pop();
                si_size--;
                so_size++;
            }
            T val = stack_out.top();
            so_size--;
            stack_out.pop();
            return val;
        }
        else {
            cout << "Queue is Empty" << endl;
            return T();
        }
    }

    // 3. front
    T front () {
        if(so_size > 0) {
            return stack_out.top();
        }
        else if (si_size > 0) {
            while(si_size != 0) {
                stack_out.push(stack_in.top());
                stack_in.pop();
                si_size--;
                so_size++;
            }

            return stack_out.top();
        }
        else {
            cout << "Queue is Empty" << endl;
            return T();
        }
    }

    // 4. Display
    void display () {
        if (so_size == 0 && si_size == 0) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Elements are :";

        // Print elements in stack_out (from top to bottom)
        stack<T> temp_out = stack_out;
        while (!temp_out.empty()) {
            cout << " " << temp_out.top();
            temp_out.pop();
        }

        // Print elements in stack_in (from bottom to top)
        stack<T> temp_in = stack_in;
        stack<T> temp_reversed;
        while (!temp_in.empty()) {
            temp_reversed.push(temp_in.top());
            temp_in.pop();
        }
        while (!temp_reversed.empty()) {
            cout << " " << temp_reversed.top();
            temp_reversed.pop();
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
    
    // 4. Front element
    cout << endl << "4." << endl;
    cout << "Front element is : " << q.front() << endl;

    return 0;
}
