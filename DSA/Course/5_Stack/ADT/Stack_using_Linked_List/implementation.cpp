#include <bits/stdc++.h>
#include <new>
#include <nl_types.h>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> * next;

    // constructors
    Node () : next(nullptr) {}
    Node (T d) : data(d), next(nullptr) {}
};



template<typename T>
class Stack {
    Node<T> * TOP;  //head
    int size;

public :
    // constructors
    Stack () {
        size = 0;
        TOP = nullptr;
    }

    // destructor
    ~Stack () {
        while(TOP != nullptr) {
            auto temp = TOP;
            TOP = TOP->next;
            delete temp;
        }
    }

    // Operations on abstrect data type

    // 1. Push
    void push(T val) {
        Node<T> *temp;
        try {
            temp = new Node<T>(val);
        }
        catch (bad_alloc& e) {
            cout << "Stack overflow : failed to push" << endl;
            return;
        }

        temp->next = TOP;
        TOP = temp;
        size++;
    }

    // 2. Pop
    void pop() {
        if (TOP == nullptr) {
            cout << "Stack underflow : failed to pop" << endl;
        } else {
            auto temp = TOP;
            TOP = TOP->next;
            delete temp;
            size--;
        }
    }

    // 3. Top
    T top() {
        if (TOP == nullptr) {
            cout << "Stack underflow : failed to return top" << endl;
            return T();
        }else {
            return TOP->data;
        }
    }

    // 4. Peek
    T peek(int index) {
        int v_a = index - 1;
        if(v_a < 0 || v_a >= size) {
            cout << "Invalid index" << endl;
            return T() ;
        }

        auto p = TOP;
        while (v_a--) {
            p = p->next;
        }

        return p->data;
    }

    // 5. check if empty
    bool isEmpty() {
        if(TOP == nullptr) {
            return true;
        }

        return false;
    }

};

int main () {
    Stack<int> s;

    // 1. Push
    cout << endl << "1." << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "Pushed 5 elements." << endl;

    // 2. Peek
    cout << endl << "2." << endl;
    cout << "Peek 1st element from top: " << s.peek(1) << endl;
    cout << "Peek 3rd element from top: " << s.peek(3) << endl;

    // 3. Top
    cout << endl << "3." << endl;
    cout << "Top element is: " << s.top() << endl;

    // 4. Pop
    cout << endl << "4." << endl;
    s.pop();
    cout << "Popped top element." << endl;
    cout << "New Top element is: " << s.top() << endl;

    // 5. Check isEmpty
    cout << endl << "5." << endl;
    cout << "Is the stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
