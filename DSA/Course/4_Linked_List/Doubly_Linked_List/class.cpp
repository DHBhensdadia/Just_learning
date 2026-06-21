#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    Node<T>* prev;
    T data;
    Node<T>* next;

    Node () : prev(nullptr), next(nullptr) {}
    Node (T d) : prev(nullptr), data(d), next(nullptr) {}
    Node (Node<T>* p, T d) : prev(p), data(d) {}
};


template<typename T>
class DoublyLL {
    Node<T>* head = nullptr;

    void clear () {
        while (head != nullptr) {
            Node<T> * temp = head;
            head = head->next;
            delete temp;
        }
    }


    public :

    // constrctors
    DoublyLL () = default;
    DoublyLL (T hd) {
        head = new Node<T> (hd);
    }
    DoublyLL (T *arr, int size)
    {
        if (size == 0)
        {
            return;
        }
        Node<T> *p = new Node<T>(arr[0]);
        head = p;
        for (int i = 1; i < size; i++)
        {
            p->next = new Node<T>(arr[i]);
            auto t = p;
            p = p->next;
            p->prev = t;
        }
        p->next = nullptr;
    }

    // destructor
    ~DoublyLL () { clear(); }

    Node<T>*& getHead () { return head; }


    // defination of all

    // 1. Diplay
    void display () {
        Node<T> * p = head;
        cout << "Elemnts are :";
        for ( ; p != nullptr; p = p -> next) {
            cout << " " << p->data;
        }
        cout << endl;
    }

    // 2. Insertion
    void insertAtIndex(Node<T> *node, int index) {
        // case 1 : insertion at begining
        if (index == 0) {
            node->next = head;
            if (head != nullptr) {
                head->prev = node;
            }
            head = node;
        }
        else {
            // case 2
            Node<T> * p = head;
            index--;
            while (index-- && p != nullptr) {
                p = p->next;
            }
            if (p == nullptr) {
                return ;
            }
            node->next = p->next;
            if (node->next != nullptr) {
                node->next->prev = node;
            }
            p->next = node;
            node->prev = p;
        }
    }

    // 3. Deletion
    void delete_(int index) {
        if (head == nullptr || index < 0) {
            return ;
        }
        if(index == 0) {
            Node<T> * temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
        }
        else {
            Node<T> * q = head;

            while (index-- && q != nullptr) {
                q = q->next;
            }
            if (q == nullptr) {
                return ;
            }

            q->prev->next = q->next;
            if (q->next != nullptr) {
                q->next->prev = q->prev;
            }
            delete q;
        }
    }

    // 4. Reverse
    void reverse () {
        if(head->next == nullptr || head == nullptr){ return;}

        Node<T> * p = head;
        while ( 1 ) {
            auto temp = p->next;
            p->next = p->prev;
            p->prev = temp;

            if(p->prev == nullptr) {
                head = p;
                break;
            }else {
                p = p->prev;
            }
        }
    }

};


int main () {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(int);
    DoublyLL<int> dll(arr, size);


    // 1. Display
    cout << endl << "1." << endl;
    dll.display();                                                                                                          // O(n)


    // 2. Insert at different positions
    cout << endl << "2." << endl;
    dll.insertAtIndex(new Node<int>(100), 0);                                                                               // O(1)
    dll.insertAtIndex(new Node<int>(200), 5);                                                                               // O(n)
    dll.insertAtIndex(new Node<int>(300), 10);                                                                              // O(n)
    dll.display();                                                              // Display to prove insertion


    // 3. Deletion from different positions
    cout << endl << "3." << endl;
    dll.delete_(0);                                                                                                         // O(1)
    dll.delete_(5);                                                                                                         // O(n)
    dll.display();                                                              // Display to prove deletion


    // 4. Reverse the doubly linked list
    cout << endl << "4." << endl;
    dll.reverse();                                                                                                          // O(n)
    dll.display();                                                              // Display to prove list reversed


    // 5. Create from array using constructor
    cout << endl << "5." << endl;
    int arr2[] = {10, 20, 30, 40, 50};
    int size2 = sizeof(arr2)/sizeof(int);
    DoublyLL<int> dll2(arr2, size2);
    dll2.display();                                                             // Display the newly created doubly linked list


    return 0;
}
