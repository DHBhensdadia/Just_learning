#include <bits/stdc++.h>
#include <stack>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T>* next;

    Node () : next(nullptr) {}
    Node (T d) : data(d), next(nullptr) {}
};
// not to delete next in distructor otherwise whole list will be deleted at onece rather than one node

template<typename T>
class LinkedList {
    Node<T>* head = nullptr;

    void clear () {
        while (head != nullptr) {
            Node<T> * temp = head;
            head = head->next;
            delete temp;
        }
    }

  public :

    LinkedList () = default;
    ~LinkedList () { clear(); }

    LinkedList (LinkedList&& other) noexcept : head(other.head) {
        other.head = nullptr;
    }
    LinkedList& operator= (LinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            other.head = nullptr;
        }
        return *this;
    }

    LinkedList (const LinkedList&) = delete;
    LinkedList& operator= (const LinkedList&) = delete;

    Node<T>*& getHead () { return head; }

// declaration of all methods :


    // 1. Display
    void display () {
        Node<T> * p = head;
        cout << "Elemnts are :";
        for ( ; p != nullptr; p = p -> next) {
            cout << " " << p->data;
        }
        cout << endl;
    }

    void rDisplay () {
        cout << "Elemnts are :";
        rd(head);
        cout << endl;
    }
    void rd (Node<T> * p) {
        if (p == nullptr) {
            return ;
        }

        cout << " " << p->data;
        rd(p->next);
    }


    // 2. count (similarly sum of all elements and avarage)
    int count () {
        int ans = 0;
        for(auto p = head; p != nullptr; p = p->next) {
            ans++;
        }
        return ans;
    }
    int rCount (Node<T> * p) {
        if (p == nullptr) {
            return 0;
        }

        return 1 + rCount(p->next);
    }


    // 3. max (similarly min)
    T maximum () {
        if (head == nullptr) {
            return T{};
        }
        T ans = head->data;
        for (auto p = head; p != nullptr; p = p->next) {
            if (p->data > ans) {
                ans = p->data;
            }
        }

        return ans;
    }
    T rMaximum (T ans, Node<T> * p) {
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

    // 4. searching algorithems (Improved)
    Node<T> *lSearch(T val) {
        Node<T> * q = nullptr;
        for (auto p = head; p != nullptr; )
        {
            if (val == p->data)
            {
                if (q != nullptr) {
                    q->next = p->next;
                    p->next = head;
                    head = p;
                }
                return p;
            }
            q = p;
            p = p->next;
        }

        return nullptr;
    }
    Node<T> * rLSearch (T val) {
        return rLSearchNode(head, val, head, nullptr);
    }
    Node<T> * rLSearchNode (Node<T> * cur, T val, Node<T> * &first, Node<T> * prev = nullptr) {

        if (cur->data == val) {

            if (prev != nullptr && cur != first) {
                prev->next = cur->next;
                cur->next = first;
                first = cur;
                head = first;
             }
            return cur;

        } else if (cur->next == nullptr){
                return nullptr;
        } else {
            return rLSearchNode(cur->next, val, first, cur);
        }

    }

    // 5. Insertion oparation
    void insertAtIndex(Node<T> *node, int index) {
        // case 1 : insertion at begining
        if (index == 0) {
            node->next = head;
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
            p->next = node;
        }
    }

    // 6. Creating a Linked list from array using insert
    // method 1 : O(n^2) :
    void createFromArray_InsertAtIndex(T *arr,int size) {
        clear();
        head = nullptr;

        for (int i = 0; i< size; i++) {
            //creating of heap node
            Node<T> * node = new Node<T>(arr[i]);
            insertAtIndex(node, i);   // O(n)
        }
    }
    // method 2 : O(n) :
    void createFromArray_InsertAtLast(T *arr, int size) {
        clear();
        Node<T> * last = nullptr;

        if(size > 0) {
            Node<T> * node = new Node<T>(arr[0]);
            insertAtIndex(node, 0);
            last = head;
        }
        for (int i = 1; i < size; i++) {
            Node<T> * node = new Node<T>(arr[i]);
            last->next = node;    // O(1)
            last = last->next;
        }
    }


    // 7. Check if liked List id Shorted or not
    bool isShorted () {
        if (head == nullptr) {
            return true;
        }
        for (auto p = head; p->next != nullptr; p = p->next) {
            if (p->data > p->next->data) {
                return false;
            }
        }
        return true;
    }
    bool rIsShorted (Node<T> * p) {
        if (p == nullptr || p->next == nullptr) {
            return true;
        }

        if (p->data > p->next->data) {
            return false;
        }

        return rIsShorted(p->next);
    }

    // 8. Inserting in a sorted Linked list
    void insertInShorted(Node<T> *node) {
        node->next = nullptr;
        // case 1 : no elements
        if (head == nullptr){
            head = node;
            return ;
        }
        // case 2 : insert at begining
        if (head->data > node->data) {
            node->next = head;
            head = node;
            return ;
        }
        // case 3 : one element only
        if (head->next == nullptr) {
            head->next = node;
            return ;
        }
        // case 4 : insert in middle or at end
        Node<T> * q = head;
        Node<T> * p = head->next;
        while (p != nullptr && p->data <= node->data) {
            q = p;
            p = p->next;
        }
        q->next = node;
        node->next = p;
    }

    // 9. Deleting from a linked list
    void delete_(int index) {
        if (head == nullptr || index < 0) {
            return ;
        }
        if(index == 0) {
            Node<T> * temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node<T> * q = head;
            index--;
            while (index-- && q->next != nullptr) {
                q = q->next;
            }
            if (q->next == nullptr) {
                return ;
            }
            Node<T> * p = q->next;
            q->next = p->next;
            delete p;
        }
    }

    // 10. Remove Duplicates from the sorted linked list
    void removeDuplicates() {
        if (head == nullptr) {
            return ;
        }
        Node<T> * q = head;
        Node<T> * p = head->next;
        while (p != nullptr) {
            if (q->data != p->data) {
                q = p;
                p = p->next;
            } else {
                q->next = p->next;
                delete p;
                p = q->next;
            }
        }
    }


    // 11. Reverting a linked list
    // Method 1 : reverting elemnts
        // auxilary array
        void reverseRE() {
            auto t = head;
            auto p = t;
            vector<T> vec;
            while ( true ) {
                vec.push_back(t->data);
                t = t->next;
                if (t == nullptr) {
                    break;
                }
            }

            for (int i = vec.size() - 1; i >= 0; i--) {
                p->data = vec[i];
                p = p->next;
            }

        }
    // Method 2 : reverting links
    // Sliding pointers
    void reverseSP() {
        Node<T> * p = head;
        Node<T> * q = nullptr;
        Node<T> * r = nullptr;

        while(p != nullptr) {
            r=q;
            q=p;
            p=p->next;
            q->next = r;
        }
        head = q;
    }
    // Recursive reverting a linked list
    void rReverse() {
        rReverseNode(head, nullptr);
    }
    void rReverseNode(Node<T> * p, Node<T> * q) {
        if (p == nullptr) {
            head = q;
            return;
        }
        rReverseNode(p->next, p);
        p->next = q;
        return;
    }


    // 12. Concatination of two linked list
    void concatenate(Node<T> *second) {
        if (second == nullptr) {
            return ;
        }
        if (head == nullptr) {
            head = second;
            return ;
        }
        auto * p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = second;
    }

    // 13. Merging two sorted linked lists
    Node<T> * mergeToNew(Node<T> *second) {
        Node<T> *first = nullptr, *last = nullptr;
        Node<T> * p = head, * q = second;

        if (p == nullptr) {
            return q;
        }
        if (q == nullptr) {
            return p;
        }

        if (p->data > q->data) {
            first = new Node<T>(q->data);
            last = first;
            q = q->next;
        } else {
            first = new Node<T>(p->data);
            last = first;
            p = p->next;
        }

        while (p!=nullptr && q!=nullptr) {
            if (p->data > q->data) {
                last->next = new Node<T>(q->data);
                last = last->next;
                q = q->next;
            } else {
                last->next = new Node<T>(p->data);
                last = last->next;
                p = p->next;
            }
        }
        while (p!=nullptr) {
            last->next = new Node<T>(p->data);
            last = last->next;
            p = p->next;
        }
        while (q!=nullptr) {
            last->next = new Node<T>(q->data);
            last = last->next;
            q = q->next;
        }

        return first;
    }
    void merge(Node<T> *second){
        if (head == nullptr) {
            head = second;
            return ;
        }
        if (second == nullptr) {
            return ;
        }

        Node<T> *third = nullptr, *last = nullptr;
        Node<T> * first = head;
        if (first->data > second->data) {
            third = second;
            last = third;
            second = second->next;
        } else {
            third = first;
            last = third;
            first = first->next;
        }
        while (first != nullptr && second != nullptr) {
            if (first->data > second->data) {
                last->next = second;
                last = last->next;
                second = second->next;
            }else {
                last->next = first;
                last = last->next;
                first = first->next;
            }
        }

        if (first != nullptr) {
            last->next = first;
        } else {
            last->next = second;
        }

        head = third;
        return;
    }

    // 14. check if linked list is looped or linear ?
    bool checkLoop() {
        if (head == nullptr) return false;
        Node<T>* p = head, * q = head;

        while(p != nullptr && q != nullptr && q->next != nullptr) {
            p = p->next;
            q = q->next->next;
            if (p == q) return true;
        }
        return false;
    }


    // Challenges
    // 1 : Finding middle element of a linked list
    Node<T> * middle () {
        auto p = head;
        auto q = head;

        while (q != nullptr) {
            q = (q==nullptr) ? (nullptr) : q->next;
            q = (q==nullptr) ? (nullptr) : q->next;
            p = (q==nullptr) ? p : p->next;
        }

        return p;
    }
    // 2 : Finding intersecting point of two linked list
    Node<T> * Intersection (LinkedList<T> * dif) {
        auto p = head;
        auto q = dif->getHead();

        stack<Node<T> *> ps;
        stack<Node<T> *> qs;

        while (p!=nullptr) {
            ps.push(p);
            p = p->next;
        }
        while (q != nullptr){
            qs.push(q);
            q = q->next;
        }

        Node<T> * t = nullptr;
        while (!ps.empty() && !qs.empty() && ps.top() == qs.top()) {
            t = ps.top();
            ps.pop();
            qs.pop();
        }

        return t;
    }



    static LinkedList<T> createFromArray(T * arr, int size) {
        LinkedList<T> list;
        if (size <= 0) {
            return list;
        }
        list.head = new Node<T>(arr[0]);

        Node<T> * p = list.head;
        for (int i = 1; i < size; i++){
            p->next = new Node<T>(arr[i]);
            p = p->next;
        }
        p->next = nullptr;

        return list;
    }


};



int main () {
    int arr[] = {1,2,3,4,5,6,2,8,12,13,53,24,4,2};
    int size = sizeof(arr)/sizeof(int);
    LinkedList<int> ll = LinkedList<int>::createFromArray(arr, size);


    // 1
    cout <<endl << "1."<< endl;
    ll.display();                                                                                                           // O(n)
    ll.rDisplay();                                                                                                          // O(n)


    // 2
        cout << endl << "2." << endl;
    cout << "Count : " << ll.count() << ", ";                                                                               // O(n)
    cout << ll.rCount(ll.getHead()) << endl;                                                                                // O(n)


    // 3
        cout << endl << "3." << endl;
    cout << "Maximum element is : " << ll.maximum() << ", ";                                                                // O(n)
    cout << ll.rMaximum(ll.getHead()->data, ll.getHead()) << endl;                                                          // O(n)


    // 4
        cout << endl << "4." << endl;
    Node<int> * temp = ll.lSearch(12);                                                                                      // O(n)
    Node<int> * r_temp = ll.rLSearch(53);                                                                                   // O(n)
    cout << "Searched element is : " << (temp ? to_string(temp->data) : "Not found");
    cout << ", " << (r_temp ? to_string(r_temp->data) : "Not found") << endl;

    ll.display(); // Display list to prove 53 moved to the front


    // 5
        cout << endl << "5." << endl;
    ll.insertAtIndex(new Node<int>(100), 0);                                                                                // O(1)
    ll.insertAtIndex(new Node<int>(200), 5);                                                                                // O(n)
    ll.display(); // Display list to prove 100 and 200 inserted at correct positions


    // 6.1
        cout << endl << "6.1." << endl;
    int arr2[] = {10, 20, 30, 40, 50};
    int size2 = sizeof(arr2)/sizeof(int);
    LinkedList<int> ll2;
    ll2.createFromArray_InsertAtIndex(arr2, size2);                                                                         // O(n^2)
    ll2.display(); // Display list to prove elements inserted correctly
    // 6.2
        cout << "6.2." << endl;
    LinkedList<int> ll3;
    ll3.createFromArray_InsertAtLast(arr2, size2);                                                                          // O(n)
    ll3.display(); // Display list to prove elements inserted correctly


    // 7
        cout << endl << "7." << endl;
    cout << "Is the linked list sorted? " << (ll.isShorted() ? "Yes" : "No") << ", ";                                       // O(n)
    cout << (ll.rIsShorted(ll.getHead()) ? "Yes" : "No") << endl;


    // 8
        cout << endl << "8." << endl;
    ll2.insertInShorted(new Node<int>(25));
    ll2.insertInShorted(new Node<int>(30));                                                                                 // O(n)
    ll2.display(); // Display list to prove 25 inserted correctly


    // 9
        cout << endl << "9." << endl;
    ll.delete_(0);                                                                                                          // O(1)
    ll.delete_(5);                                                                                                          // O(n)
    ll.display(); // Display list to prove elements deleted correctly


    // 10
        cout << endl << "10." << endl;
    ll2.removeDuplicates();                                                                                                 // O(n)
    ll2.display(); // Display list to prove duplicates removed correctly


    // 11.1
        cout << endl << "11.1." << endl;
    ll2.reverseRE();                                                                                                        // O(n)
    ll2.display(); // Display list to prove elements reversed correctly
    // 11.2
            cout << "11.2." << endl;
    ll2.reverseSP();                                                                                                        // O(n)
    ll2.display(); // Display list to prove elements reversed correctly
    // 11.3
            cout << "11.3." << endl;
    ll2.rReverse();                                                                                                         // O(n)
    ll2.display(); // Display list to prove elements reversed correctly


    // 12
        cout << endl << "12." << endl;
    ll.concatenate(ll3.getHead());                                                                                          // O(n)
    ll.display(); // Display list to prove lists concatenated correctly


    // 13.1
        cout << endl << "13.1." << endl;
    Node<int> * mergedHead = ll2.mergeToNew(ll3.getHead());
    LinkedList<int> mergedList;
    mergedList.concatenate(mergedHead); // Use concatenate to set head of mergedList
    mergedList.display(); // Display list to prove lists merged correctly
    // 13.2
        cout << "13.2." << endl;
    ll2.merge(ll3.getHead());
    ll2.display(); // Display list to prove lists merged correctly


    // 14.
        cout << endl << "14." << endl;
    cout << "Is the linked list looped? " << (ll.checkLoop() ? "Yes" : "No") << endl;                                       // O(n)

    // Challenges
    // 1
        cout << endl << "Challenge 1." << endl;
    Node<int> * middleNode = ll.middle();
    cout << "Middle element is : " << (middleNode ? to_string(middleNode->data) : "List is empty") << endl; // Display middle element.         // O(n)
    // 2
        cout << endl << "Challenge 2." << endl;
    int arr4[] = {5, 10, 15, 20, 25};
    int size4 = sizeof(arr4)/sizeof(int);
    LinkedList<int> ll4 = LinkedList<int>::createFromArray(arr4, size4);   
    Node<int> * intersectionNode = ll.Intersection(&ll4);
    cout << "Intersecting element is : " << (intersectionNode ? to_string(intersectionNode->data) : "No intersection") << endl; // Display intersecting element.         // O(n)


    return 0;
}
