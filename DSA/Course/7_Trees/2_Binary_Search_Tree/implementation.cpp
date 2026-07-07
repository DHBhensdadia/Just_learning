#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node {
public :
    Node<T> * left;
    T data;
    Node<T> * right;

    // constructors
    Node () {
        left = nullptr;
        right = nullptr;
    }
    Node (T x) {
        left = nullptr;
        data = x;
        right = nullptr;
    }
};

template<typename T>
class BST {
    Node<T> * root;

    // Helper to delete tree recursively
    void Delete (Node<T> * n) {
        if(n == nullptr) {
            return;
        }
        Delete (n->left);
        if (n->left != nullptr) delete n->left;
        Delete (n->right);
        if (n->right != nullptr) delete n->right;
    }

public :
    // constructors -- destructor
    BST () { root = nullptr; }
    ~BST () {
        Delete (root);
        if (root != nullptr) delete root;
    }

    /***************************************
     *          Operations on BST          *
     ***************************************/


    // Display
    // Inorder
    void iInorder () {
        if (root == nullptr) { return; }

        stack<Node<T> *> nps;
        auto t = root;

        while (t != nullptr || !nps.empty()) {
            if (t != nullptr) {
                nps.push(t);
                t = t->left;
            } else {
                t = nps.top();
                cout << " " << t->data;
                nps.pop();
                t = t->right;
            }
        }
    }

    // Search
    // itrative
    bool iSearch (T key) {
        auto t = root;

        while (t != nullptr) {
            if (t->data == key) {
                return true;
            } else if (t->data > key) {
                t = t->left;
            } else if (t->data < key) {
                t = t->right;
            }
        }

        return false;
    }
    // recursive
    bool rSearch (T key) {
        return rs (root, key);
    }
    bool rs (Node<T> * t, T key) {
        if (t == nullptr)   return false;

        if (t->data == key)     return true;
        else if (t->data > key) return rs(t->left, key);
        else if (t->data < key) return rs(t->right, key);

        return false;
    }

    // Inertion
    // Itrative
    void iInsert (T data) {
        if (iSearch(data)) { return; }
        if (root == nullptr) {
            root = new Node<T>(data);
            return ;
        }

        Node<T> *s, *t;
        t = root;
        while (t != nullptr) {
            s = t;
            if (t->data > data) { t = t->left;  }
            else                { t = t->right; }
        }

        t = new Node<T>(data);
        if (s->data > data) {
            s->left = t;
        } else {
            s->right = t;
        }
    }
    // recursive
    void rInsert (T data) {
        // Fix: Assign the result back to root so we don't leak memory on an empty tree
        root = ri(root, data);
    }
    Node<T> *ri (Node<T> * u, T data) {

        if (u == nullptr) {
            u = new Node<T>(data);
            return u;
        } else if (u->data > data) {
            u->left = ri(u->left, data);
        } else if (u->data < data) {
            u->right = ri(u->right, data);
        } else if (u->data == data) {
            return u;
        }

        return u;
    }

    // Creation
    void create(vector<T> arr) {
        for (auto i : arr) {
            this->iInsert(i);
        }
    }

    // Deletion
    // recursive delete
    void delete_(T data) {
        // Fix: Assign the result back to root so it updates if the root is deleted
        root = rDelete(root, data);
    }
    Node<T>* rDelete(Node<T>* p, T key) {
        Node<T>* q;
        if (p == nullptr) {
            return nullptr;
        }

        // leaf node condition
        if (p->left == nullptr && p->right == nullptr) {
            // Fix: No longer need the (p == root) hack here!
            delete p;
            return nullptr;
        }

        // search for the node
        if (key < p->data) {
            p->left = rDelete(p->left, key);
        }
        else if (key > p->data) {
            p->right = rDelete(p->right, key);
        }
        else {
            // Node found, replace with inorder predecessor or successor based on height
            if (height(p->left) > height(p->right)) {
                q = inPre(p->left);
                p->data = q->data;
                p->left = rDelete(p->left, q->data);
            }
            else {
                q = inSucc(p->right);
                p->data = q->data;
                p->right = rDelete(p->right, q->data);
            }
        }
        return p;
    }
    // Inorder predecessor
    Node<T>* inPre(Node<T>* p) {
        while (p != nullptr && p->right != nullptr) {
            p = p->right;
        }
        return p;
    }

    // Inorder successor
    Node<T>* inSucc(Node<T>* p) {
        while (p != nullptr && p->left != nullptr) {
            p = p->left;
        }
        return p;
    }

    // Height
    int height(Node<T>* u) {
        if (u == nullptr) { return 0; }

        int x = height(u->left);
        int y = height(u->right);

        return (x > y) ? x + 1 : y + 1;
    }

    // find
    Node<T> *find(Node<T> *u,T val) {

        while (u != nullptr) {
            if (u->data == val) {
                return u;
            } else if (u->data > val) {
                u = u->left;
            } else if (u->data < val) {
                u = u->right;
            }
        }

        return nullptr;
    }

    // BTS generation from preorder
    void generateFromPreorder (vector<T> pre) {
        Delete (root);
        if (root != nullptr) delete root;
        if (!pre.size()) {
            root = nullptr;
            return;
        }

        root = new Node<T>(pre[0]);
        auto p = root;
        stack<Node<T> *> s;

        for (int i = 1; i < pre.size(); i++) {
            if(p->data > pre[i]) {
                p->left = new Node<T>(pre[i]);
                s.emplace(p);
                p = p->left;
            } else {
                // Fix: Keep popping from the stack as long as the stack top is smaller than pre[i].
                // This ensures we climb back up the tree to find the correct ancestor.
                while(!s.empty() && s.top()->data < pre[i]) {
                    p = s.top();
                    s.pop();
                }
                // Once we find the correct ancestor, attach pre[i] as its right child
                p->right = new Node<T>(pre[i]);
                // Fix: Move the pointer forward so subsequent nodes attach to this new node!
                p = p->right; 
            }
        }
    }

};



int main () {
    BST<int> bst;

    cout << "Creation" << endl;
    cout << "\n1. Creating Binary Search Tree" << endl;
    vector<int> arr = {30, 20, 40, 10, 25, 35, 50};
    bst.create(arr);



    cout << "\n\nTraversals" << endl;
    cout << "\n2 : Iterative Traversals" << endl;

    cout << "2.1 : Inorder " << endl;
    cout << "Data :";
    bst.iInorder();
    cout << endl;



    cout << "\n\nOperations" << endl;
    cout << "\n3 : Searching" << endl;

    cout << "3.1 : Iterative Search" << endl;
    cout << "Search 25 : " << (bst.iSearch(25) ? "Found" : "Not Found") << endl;

    cout << "3.2 : Recursive Search" << endl;
    cout << "Search 100 : " << (bst.rSearch(100) ? "Found" : "Not Found") << endl;



    cout << "\n4 : Deletion" << endl;
    cout << "Deleting 20" << endl;
    bst.delete_(20);

    cout << "Data :";
    bst.iInorder();
    cout << endl;



    cout << "\n\nGeneration" << endl;
    cout << "\n5. Creating Binary Search Tree from Preorder" << endl;

    vector<int> pre = {30, 20, 10, 25, 40, 35, 50};
    cout << "Preorder :";
    for (auto x : pre) { cout << ' ' << x; }
    cout << endl;

    BST<int> bst2;
    bst2.generateFromPreorder(pre);

    cout << "Created Tree from Preorder Traversal" << endl;
    cout << "Data :";
    bst2.iInorder();
    cout << endl;

    return 0;
}
