#include <bits/stdc++.h>
using namespace std;


template<typename T>
class Stack {
    T * arr;
    int TOP;
    int size;

public :
    // constructors
    Stack () {}
    Stack (int size) {
        arr = new T[size];
        this->size = size;
        TOP = -1;
    }

    // Operations on abstrect data type

    // 1. Push
    void push(T val) {
        if(TOP == size - 1) {
            cout << "Stack overflow : failed to push" << endl;
        }else {
            TOP++;
            arr[TOP] = val;
        }
    }

    // 2. Pop
    void pop() {
        if (TOP == -1) {
            cout << "Stack underflow : failed to pop" << endl;
        } else {
            arr[TOP] = 0;
            TOP--;
        }
    }

    // 3. Top
    T top() {
        if (TOP == -1) {
            cout << "Stack underflow : failed to return top" << endl;
            return T();
        }else {
            return arr[TOP];
        }
    }

    // 4. Peek
    T peek(int index) {
        int v_a = TOP + 1 - index;
        if(v_a < 0) {
            cout << "Invalid index" << endl;
            return T() ;
        }

        return arr[v_a];
    }

    // 5. check if empty
    bool isEmpty() {
        if(TOP == -1) {
            return true;
        }

        return false;
    }

    // 6. check if full
    bool isFull() {
        if (TOP + 1 == size) {
            return true;
        }

        return false;
    }
};

int main () {
    Stack<int> s(5);

    // 1. Push
    cout << endl << "1." << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "Pushed 5 elements." << endl;
    s.push(60); // Should print overflow

    // 2. Peek
    cout << endl << "2." << endl;
    cout << "Peek 1st element from top: " << s.peek(1) << endl;
    cout << "Peek 3rd element from top: " << s.peek(3) << endl;

    // 3. Top
    cout << endl << "3." << endl;
    cout << "Top element is: " << s.top() << endl;

    // 4. Check isFull
    cout << endl << "4." << endl;
    cout << "Is the stack full? " << (s.isFull() ? "Yes" : "No") << endl;

    // 5. Pop
    cout << endl << "5." << endl;
    s.pop();
    cout << "Popped top element." << endl;
    cout << "New Top element is: " << s.top() << endl;

    // 6. Check isEmpty
    cout << endl << "6." << endl;
    cout << "Is the stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
