#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;

template<typename T>
class Node {
public :
    Node<T> * left;
    T data;
    Node<T> * right;

    int hight;

    // constructors
    Node () : left(nullptr), right(nullptr), hight(0) {}
    Node (T d) : left(nullptr), data(d), right(nullptr), hight(1) {}
};

template<typename T>
class AVL {
    Node<T> * root;

public :
    // constructors
    AVL () : root(nullptr) {}

    // destructor
    ~AVL() {
        des(root);
        if(root != nullptr) { delete root; }
    }
    void des (Node<T> * u) {
        if (u == nullptr) {
            return ;
        }

        des(u->left);
        if(u->left != nullptr) { delete u->left; }
        des(u->right);
        if(u->right != nullptr) { delete u->right; }
    }

    // Declaration of all methods

    // 1. Display
    void iInrder ();
    void rInoder ();
    void ri(Node<T> * u);

    // 2. Search
    bool search(Node<T> * u, T data);

    // 3. create
    void create(vector<T> v);

    // 4. Insert
    void insert (T data);
    Node<T> * ri(Node<T> * u, T val);

    // 5. Delete
    void delete_ (T data);
    Node<T> *rd_ (Node<T> * e, T data);

        // helper methods for Insert and delete
        int hightUpdate(Node<T> * u);

        int balanceFactor(Node<T> *u);

        Node<T> * LLRotation(Node<T>* e);
        Node<T> * LRRotation(Node<T>* e);
        Node<T> * RRRotation(Node<T>* e);
        Node<T> * RLRotation(Node<T>* e);

        Node<T> *inpre (Node<T> * t);
        Node<T> *insuc (Node<T> * t);

};
    /************************************************
    *               Operations on AVL               *
    *************************************************/

    // 1. Display - Inorder - traversal
    // itrative
    template<typename T>
    void AVL<T>::iInrder () {
        auto p = root;
        stack<Node<T> *> s;

        while (p != nullptr || !s.empty()) {
            if ( p != nullptr ) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                cout << ' ' << p->data;
                p = p->right;
            }
        }
    }
    // recursive
    template<typename T>
    void AVL<T>::rInoder () {
        ri(root);
    }
    template<typename T>
    void AVL<T>::ri(Node<T> * u) {
        if (u == nullptr) {
            return;
        }
        ri(u->left);
        cout << ' ' << u->data;
        ri(u->right);
    }



    // 2. Search
    template<typename T>
    bool AVL<T>::search(Node<T> * u, T data) {
        if(u == nullptr) { return false; }

        if(u->data == data) {
            return true;
        }

        return search(u->left, data) || search(u->right, data);
    }



    // 4. Insertion
    template<typename T>
    void AVL<T>::insert (T data) {
        if(this->search(root, data)) { return; }

        root = ri (root, data);
    }
    template<typename T>
    Node<T> * AVL<T>::ri(Node<T> * u, T val) {
        // Base case : when recursion hits end it will create a new node and return it's add
        if (u == nullptr) {
            u = new Node<T> (val);
            return u;
        }

        // recursive call
        if (u->data > val) {
            u->left = ri(u->left, val);
        } else if (u->data < val) {
            u->right = ri(u->right, val);
        }
        // now we are going back to top of tree from the end point where new node is inserted

        // update hight based on child node
        u->hight = hightUpdate(u);


        // AVL validation and rotation for invalid nodes
        // calculation for balance factor
        int bf = balanceFactor(u);

        if (bf == 2) {          // heavy on LHS
            int bfl = balanceFactor(u->left);
            switch (bfl) {
                case 1 :    // heavy on LHS
                    return LLRotation(u);
                case -1 :   // heavy on RHS
                    return LRRotation(u);
            }
        } else if (bf == -2) {          // heavy on RHS
            int bfr = balanceFactor(u->right);
            switch (bfr) {
                case 1 :    // heavy on LHS
                    return RLRotation(u);
                case -1 :   // heavy on RHS
                    return RRRotation(u);
            }
        }

        return u;
    }
    template<typename T>
    int AVL<T>::hightUpdate(Node<T> * u) {
        if (u == nullptr) { return 0; }

        int hl = (u->left != nullptr) ? u->left->hight : 0;
        int hr = (u->right != nullptr) ? u->right->hight : 0;

        return ((hl>hr) ? hl : hr) + 1;
    }
    template<typename T>
    int AVL<T>::balanceFactor(Node<T> *u) {
        if (u == nullptr) { return 0; }

        int hl = (u->left != nullptr) ? u->left->hight : 0;
        int hr = (u->right != nullptr) ? u->right->hight : 0;

        return hl - hr;
    }
    // Rotations :
    // LL Rotation
    template<typename T>
    Node<T> * AVL<T>::LLRotation(Node<T>* e) {
        auto p = e;
        auto q = e->left;

        p->left = q->right;
        q->right = p;

        // hight upgradation
        p->hight = hightUpdate(p);  // first p becouse it's child of q thous q's hight depends on it
        q->hight = hightUpdate(q);

        e = q;
        return e;
    }
    // RR Rotation
    template<typename T>
    Node<T> * AVL<T>::RRRotation(Node<T>* e) {
        auto p = e;
        auto q = e->right;

        p->right = q->left;
        q->left = p;

        // hight upgradation
        p->hight = hightUpdate(p);  // first p becouse it's child of q thous q's hight depends on it
        q->hight = hightUpdate(q);

        e = q;
        return e;
    }
    // LR Rotation
    template<typename T>
    Node<T> * AVL<T>::LRRotation(Node<T> *e) {
        auto p = e;
        auto q = e->left;
        auto r = q->right;

        q->right = r->left;
        p->left = r->right;
        r->left = q;
        r->right = p;

        // hight upgradation
        q->hight = hightUpdate(q);
        p->hight = hightUpdate(p);
        r->hight = hightUpdate(r);

        e = r;
        return e;
    }
    // RL Rotation
    template<typename T>
    Node<T> * AVL<T>::RLRotation(Node<T> *e) {
        auto p = e;
        auto q = e->right;
        auto r = q->left;

        p->right = r->left;
        q->left = r->right;
        r->left = p;
        r->right = q;

        // hight upgradation
        q->hight = hightUpdate(q);
        p->hight = hightUpdate(p);
        r->hight = hightUpdate(r);

        e = r;
        return e;
    }



    // 3. Creation - from vector
    template<typename T>
    void AVL<T>::create(vector<T> v) {
        // cleaning tree first
        des(root);
        if(root != nullptr) {
            delete root;
            root = nullptr;
        }

        // inserting values one by one
        for(auto i : v) {
            this->insert(i);
        }
    }


    
    // 5. Deletion
    template<typename T>
    void AVL<T>::delete_ (T data) {
        if (!(this->search(root, data))) {
            return ;
        }

        root = rd_(root, data);
    }
    template<typename T>
    Node<T> *AVL<T>::rd_ (Node<T> * e, T data) {
        if (e == nullptr) {
            return nullptr;
        }

        // special case
        if (e ->left == nullptr && e->right == nullptr) {
            if (e == root) {
                root = nullptr;
            }
            delete e;
            return nullptr;
        }

        if (data < e->data) {
            e->left = rd_(e->left, data);
        } else if (data > e->data) {
            e->right = rd_ (e->right, data);
        } else {
            if (e->left->hight > e->right->hight) {
                Node<T> *in_pre = inpre(e);
                e->data = in_pre->data;
                e->left = rd_(e->left, in_pre->data);
            } else {
                Node<T> * in_suc = insuc(e);
                e->data = in_suc->data;
                e->right = rd_(e->right, in_suc->data);
            }
        }

        // update hight based on child node
        e->hight = hightUpdate(e);

        // AVL validation and rotation for invalid nodes
        // calculation for balance factor
        int bf = balanceFactor(e);

        if (bf == 2) {          // heavy on LHS
            int bfl = balanceFactor(e->left);
            switch (bfl) {
                case 1 :    // heavy on LHS
                    return LLRotation(e);
                    break;
                case -1 :   // heavy on RHS
                    return LRRotation(e);
                    break;
                case 0 :
                    return LLRotation(e);
                    break;
            }
        } else if (bf == -2) {          // heavy on RHS
            int bfr = balanceFactor(e->right);
            switch (bfr) {
                case 1 :    // heavy on LHS
                    return RLRotation(e);
                case -1 :   // heavy on RHS
                    return RRRotation(e);
                case 0 :
                    return RRRotation(e);
            }
        }

        return e;
    }
    // Inorder predecessor
    template<typename T>
    Node<T> *AVL<T>::inpre (Node<T> * t) {
        if(t == nullptr || t->left == nullptr) {
            return nullptr;
        }

        t = t->left;
        auto s = t;
        while(t != nullptr) {
            s = t;
            t = t->right;
        }
        return s;
    }
    // Inorder successor
    template<typename T>
    Node<T> *AVL<T>::insuc (Node<T> * t) {
        if(t == nullptr || t->right == nullptr) {
            return nullptr;
        }

        t = t->right;
        while(t->left != nullptr) {
            t = t->left;
        }
        return t;
    }





int main (){
    AVL<int> tree;
    vector<int> v = {10, 20, 30, 25, 28, 27,5};
    tree.create(v);

    tree.rInoder(); cout << endl;

    tree.delete_(28);

    tree.rInoder(); cout << endl;

    return 0;

}
