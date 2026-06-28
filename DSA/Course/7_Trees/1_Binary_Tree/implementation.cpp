#include <bits/stdc++.h>
#include <ios>
#include <stack>
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
class Tree {
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
    // constructors
    Tree () { root = nullptr; }

    // destructor
    ~Tree () {
        Delete (root);
        if (root != nullptr) delete root;
    }


    // Operations on Tree

    // 1. creation of costom binary tree via user input
    void createTree () {
        cout << "Provide the data to be filled in Binary Tree (type '-1' to skip perticular node) :" << endl;
        cout << "\troot\t: ";

        T rt;
        cin >> rt;
        if (rt == -1) return;

        root = new Node<T>(rt);

        queue<Node<T> *> adn;
        adn.push(root);

        while(! adn.empty() ){
            Node<T> *addr = adn.front();
            adn.pop();

            T Ld;
            cout << "\tLeft of " << addr->data << "\t: ";
            cin >> Ld;
            if (Ld != -1) {
                addr->left = new Node<T>(Ld);
                adn.push(addr->left);
            }

            T Rd;
            cout << "\tRight of " << addr->data << "\t: ";
            cin >> Rd;
            if (Rd != -1) {
                addr->right = new Node<T>(Rd);
                adn.push(addr->right);
            }

            cout << endl;
        }

        return;
    }

    // 2. All display methodologies

    // Wrapper methods to start from root
    void preorder() { preorder(root); cout << endl; }
    void inorder() { inorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }

    // 2.1 : preorder
    void preorder (Node<T> * u) {
        if (u == nullptr) return;
        cout << ' ' << u->data;
        preorder(u->left);
        preorder(u->right);
    }
    // 2.2 : inorder
    void inorder (Node<T> * u) {
        if (u == nullptr) return;
        inorder(u->left);
        cout << ' ' << u->data;
        inorder(u->right);
    }
    // 2.3 : postorder
    void postorder (Node<T> * u) {
        if (u == nullptr) return;
        postorder(u->left);
        postorder(u->right);
        cout << ' ' << u->data;
    }
    // 2.4 : levelorder
    void levelorder () {
        if (root == nullptr) return;
        queue<Node<T> *> curr;
        queue<Node<T> *> next;
        curr.push(root);
        int level = 0;

        while (! curr.empty()) {
            cout << "Level " << level++ << " :";
            while(! curr.empty()) {
                Node<T> *ad = curr.front();
                curr.pop();
                cout << ' ' << ad->data;
                if(ad->left != nullptr) {
                    next.push(ad->left);
                }
                if (ad->right != nullptr) {
                    next.push(ad->right);
                }
            }

            while (! next.empty()) {
                curr.push(next.front());
                next.pop();
            }
            cout << endl;
        }
    }

    // 3 : hight
    int hight() { return hight(root); }
    int hight (Node<T> * u) {
        if (u == nullptr) { return 0; }

        int x = hight(u->left);
        int y = hight(u->right);

        if (x > y) { return x+1; }
        else       { return y+1; }
    }

};



int main () {
    Tree<int> t;

    cout << "1. Creating Binary Tree" << endl;
    t.createTree();


    cout << "\n2.1 : Preorder Traversal" << endl;
    cout << "Data :";
    t.preorder();

    cout << "\n2.2 : Inorder Traversal" << endl;
    cout << "Data :";
    t.inorder();

    cout << "\n2.3 : Postorder Traversal" << endl;
    cout << "Data :";
    t.postorder();

    cout << "\n2.4 : Levelorder Traversal" << endl;
    t.levelorder();

    cout << "\n3 : Height of Tree" << endl;
    cout << "Hight : " << t.hight() << endl;

    return 0;
}
