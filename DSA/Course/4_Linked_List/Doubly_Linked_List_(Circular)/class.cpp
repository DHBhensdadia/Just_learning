#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    Node<T>* prev;
    T data;
    Node<T>* next;

    Node () : prev(nullptr), next(nullptr) {}
    Node (T d) : prev(nullptr), data(d), next(nullptr) {}
};


template<typename T>
class CircularDoublyLL {
    Node<T>* head = nullptr;

    void clear () {
        if (head == nullptr) {
            return;
        }
        Node<T> *p = head->next;
        while (p != head) {
            Node<T> *temp = p;
            p = p->next;
            delete temp;
        }
        delete head;
        head = nullptr;
    }


    public :

    // constrctors
    CircularDoublyLL () = default;
    CircularDoublyLL (T hd) {
        head = new Node<T> (hd);
        head->next = head;
        head->prev = head;
    }
    CircularDoublyLL (T *arr, int size)
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
            p->next->prev = p;
            p = p->next;
        }
        p->next = head;
        head->prev = p;
    }

    // destructor
    ~CircularDoublyLL () { clear(); }

    Node<T>*& getHead () { return head; }


    // defination of all

    // 1. Diplay
    void display () {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node<T> * p = head;
        cout << "Elemnts are :";
        do {
            cout << " " << p->data;
            p = p -> next;
        } while (p != head);
        cout << endl;
    }

    // 2. Insertion
    void insertAtIndex(Node<T> *node, int index) {
        // case 1 : empty list
        if (head == nullptr) {
            head = node;
            head->next = head;
            head->prev = head;
            return;
        }
        // case 2 : insertion at begining
        if (index == 0) {
            node->next = head;
            node->prev = head->prev;
            head->prev->next = node;
            head->prev = node;
            head = node;
        }
        else {
            // case 3
            Node<T> * p = head;
            index--;
            while (index-- && p->next != head) {
                p = p->next;
            }
            node->next = p->next;
            node->prev = p;
            p->next->prev = node;
            p->next = node;
        }
    }

    // 3. Deletion
    void delete_(int index) {
        if (head == nullptr || index < 0) {
            return ;
        }
        // case 1 : only one node
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        if(index == 0) {
            Node<T> * temp = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            delete temp;
        }
        else {
            Node<T> * q = head;

            while (index-- && q->next != head) {
                q = q->next;
            }
            if (q == head) {
                return ;
            }

            q->prev->next = q->next;
            q->next->prev = q->prev;
            delete q;
        }
    }

};


int main () {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(int);
    CircularDoublyLL<int> cdll(arr, size);


    // 1. Display
    cout << endl << "1." << endl;
    cdll.display();                                                                                                         // O(n)


    // 2. Insert at different positions
    cout << endl << "2." << endl;
    cdll.insertAtIndex(new Node<int>(100), 0);                                                                              // O(1)
    cdll.insertAtIndex(new Node<int>(200), 5);                                                                              // O(n)
    cdll.insertAtIndex(new Node<int>(300), 10);                                                                             // O(n)
    cdll.display();                                                              // Display to prove insertion


    // 3. Deletion from different positions
    cout << endl << "3." << endl;
    cdll.delete_(0);                                                                                                        // O(1)
    cdll.delete_(5);                                                                                                        // O(n)
    cdll.display();                                                              // Display to prove deletion


    return 0;
}
