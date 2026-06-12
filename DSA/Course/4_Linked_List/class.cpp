#include <bits/stdc++.h>
using namespace std;

template<typename T>
class LinkedList {
  public :
    T data;
    LinkedList<T> * next;

// Constructor
    LinkedList () : next(nullptr) {}
    LinkedList (T d) : data(d), next(nullptr) {}
// not to delete next in distructor otherwise whole list will be deleted at onece rather than one node

// declaration of all methods :

    // Display
    void display () {
        LinkedList<T> * p = this;
        cout << "Elemnts of the Linked list are :";
        for ( ; p != nullptr; p = p -> next) {
            cout << " " << p->data;
        }
        cout << endl;
    }

    void rDisplay () {
        cout << "Elemnts of the Linked List are :";
        rd(this /*this*/);
        cout << endl;
    }
    void rd (LinkedList<T> * p) {
        if (p == nullptr) {
            return ;
        }

        cout << " " << p->data;
        rd(p->next);
    }

    // count (similarly sum of all elements and avarage)
    int count () {
        int ans = 0;
        for(auto p = this; p != nullptr; p = p->next) {
            ans++;
        }
        return ans;
    }
    int rCount (LinkedList<T> * p) {
        if (p == nullptr) {
            return 0;
        }

        
        return 1 + rCount(p->next);
    }

    // max (similarly min)
    T maximum () {
        T ans = this->data;
        for (auto p = this; p != nullptr; p = p->next) {
            if (p->data > ans) {
                ans = p->data;
            }
        }

        return ans;
    }
    T rMaximum (T ans, LinkedList<T> * p) {
        if(p->next == nullptr) {
            if(p->data > ans) {
                return p->data;
            }else {
                return ans;
            }
        }

        ans = rMaximum(ans, p->next);

        if(p->data > ans) {
            return p->data;
        }else {
            return ans;
        }
    }

    // searching algorithems (Improved)
    LinkedList<T> *lSearch(T val, LinkedList<T> * &first) {
        LinkedList<T> * q = nullptr;
        for (auto p = first; p != nullptr; )
        {
            if (val == p->data)
            {
                if (q != nullptr) {
                    q->next = p->next;
                    p->next = first;
                    first = p;
                }
                return p;
            }
            q = p;
            p = p->next;
        }

        return nullptr;
    }

    LinkedList<T> * rLSearch (T val,LinkedList<T> * &first, LinkedList<T> * prev = nullptr) {
        
        if (this->data == val) {

            if (prev != nullptr && this != first) {
                prev->next = this->next;
                this->next = first;
                first = this;
            } 
            return this;
        
        } else if (this->next == nullptr){
                return nullptr;
        } else {
            return next->rLSearch(val, first, this);
        }
        
    }
};

template<typename T>
LinkedList<T> * createFromArray(T * arr, int size) {
    LinkedList<T> * head = new LinkedList<T>;
    head->data = arr[0];

    LinkedList<T> * p = head;
    for (int i = 1; i < size; i++){
        p->next = new LinkedList<T>;
        p = p->next;
        p->data = arr[i];
    }
    p->next = nullptr;

    return head;
}



int main () {
    int arr[] = {1,2,3,4,5,6,2,8,12,13,53,24,4,2};
    int size = sizeof(arr)/sizeof(int);
    LinkedList<int> * ll = createFromArray(arr, size);

    ll->display();                                                                                                          // O(n)
    ll->rDisplay();                                                                                                         // O(n)

    cout << "Count : " << ll->count() << ", ";                                                                              // O(n)
    cout << ll->rCount(ll) << endl;                                                                                         // O(n)

    cout << "Maximum element is : " << ll->maximum() << ", ";                                                               // O(n)
    cout << ll->rMaximum(ll->data, ll) << endl;                                                                             // O(n)

    LinkedList<int> * temp = ll->lSearch(12, ll);                                                                           // O(n)
    LinkedList<int> * r_temp = ll->rLSearch(53, ll);                                                                        // O(n)
    cout << "Searched element is : " << (temp ? to_string(temp->data) : "Not found");
    cout << ", " << (r_temp ? to_string(r_temp->data) : "Not found") << endl;

    ll->display(); // Display list to prove 53 moved to the front

    return 0;
}