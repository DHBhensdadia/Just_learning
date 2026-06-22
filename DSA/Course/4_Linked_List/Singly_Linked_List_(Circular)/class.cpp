#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;

    Node() { next = nullptr; }
    Node(T d)
    {
        data = d;
        next = nullptr;
    }
};

template <typename T>
class CircularLinkedList
{
    Node<T> *head = nullptr;

    void clear()
    {
        if (head == nullptr){ return;}

        Node<T> *p = head->next;
        while (p != head)
        {
            Node<T> *temp = p;
            p = p->next;
            delete temp;
        }
        delete p;
        head = nullptr;
    }

public:
    // constructors
    CircularLinkedList() {}
    CircularLinkedList(T h) : head(h) {}
    CircularLinkedList(T *arr, int size)
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
            p = p->next;
        }
        p->next = head;
    }

    // destructor
    ~CircularLinkedList() { clear(); }


    // defination of all methods

    // 1. Display
    void display()
    {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        cout << "Elements are : ";
        cout << head->data;
        auto t = head;
        t = t->next;
        while (t != head)
        {
            cout << " " << t->data;
            t = t->next;
        }
        cout << endl;
    }
    void rDisplay()
    {
        cout << "Elements are : ";
        rD(head);
        cout << endl;
    }
    void rD(Node<T> *p)
    {
        static bool head_used = false;

        if (head_used == true && p == head)
        {
            head_used = false;
            return;
        }

        if (p == head)
        {
            head_used = true;
        }

        cout << " " << p->data;
        rD(p->next);
    }

    // 2. Insert
    void insert(Node<T> *p, int index)
    {
        if (head == nullptr) {
            p->next = p;
            head = p;
            return;
        }

        auto t = head;
        if (t != 0)
        {
            while (--index)
            {
                t = t->next;
            }
        }
        p->next = t->next;
        t->next = p;
        if (p->next == head)
        {
            head = p;
        }
    }

    // 3. Deletion
    void delete_(int index) {
        if (head == nullptr) {return;}

        auto t = head;
        if (t != 0)
        {
            while (--index)
            {
                t = t->next;
            }
        }

        if (t->next == head) {
            auto temp = t->next;
            t->next = temp->next;
            delete temp;
            head = t->next;
        }else {
            auto temp = t->next;
            t->next = temp->next;
            delete temp;
        }
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(int);
    CircularLinkedList<int> cll(arr, size);


    // 1. Display
    cout << endl << "1." << endl;
    cll.display();                                                                                                          // O(n)
    cll.rDisplay();                                                                                                         // O(n)


    // 2. Insert at different positions
    cout << endl << "2." << endl;
    cll.insert(new Node<int>(100), 0);                                                                                      // O(1)
    cll.insert(new Node<int>(200), 5);                                                                                      // O(n)
    cll.insert(new Node<int>(300), 10);                                                                                     // O(n)
    cll.display();                                                              // Display to prove insertion


    // 3. Deletion from different positions
    cout << endl << "3." << endl;
    cll.delete_(0);                                                                                                         // O(1)
    cll.delete_(5);                                                                                                         // O(n)
    cll.display();                                                              // Display to prove deletion

    return 0;
}
