#include <bits/stdc++.h>
#include <vector>
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
    // constructors -- destructor
    Tree () { root = nullptr; }
    ~Tree () {
        Delete (root);
        if (root != nullptr) delete root;
    }

    // Operations on Tree



    // Tree creation

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

    // 8 : Creation of Binary Tree, provided preorder + inorder
    void createTreeFromTraversal (vector<T> pre, vector<T> in) {
        Delete (root);
        if (root != nullptr) delete root;

        root = cT(pre, in);
    }
    Node<T> * cT (vector<T> pre, vector<T> in) {

        if (pre.empty() || in.empty()) {
            return nullptr;
        }


        Node<T> * ans = new Node<T>;
        T head = pre[0];
        ans->data = head;

        auto turn = find(in.begin(), in.end(), head);
        vector<T> il(in.begin(), turn);
        vector<T> ir(turn + 1, in.end());

        int left_size = turn - in.begin();
        vector<T> pl(pre.begin()+1, pre.begin()+1+left_size);
        vector<T> pr(pre.begin()+1+left_size, pre.end());

        ans->left = cT(pl, il);
        ans->right = cT(pr, ir);

        return (ans);
    }



    // 2-3 : All Traversal methodologies

    // 2 Traversers using recursion
    // 2.1 : preorder
    void preorder() { preorder(root); cout << endl; }
    void preorder (Node<T> * u) {
        if (u == nullptr) return;

        cout << ' ' << u->data;
        preorder(u->left);
        preorder(u->right);
    }
    // 2.2 : inorder
    void inorder() { inorder(root); cout << endl; }
    void inorder (Node<T> * u) {
        if (u == nullptr) return;

        inorder(u->left);
        cout << ' ' << u->data;
        inorder(u->right);
    }
    // 2.3 : postorder
    void postorder() { postorder(root); cout << endl; }
    void postorder (Node<T> * u) {
        if (u == nullptr) return;

        postorder(u->left);
        postorder(u->right);
        cout << ' ' << u->data;
    }

    // 3 Traversers using Itretion
    // 3.1 : Preorder
    void iPreorder () {
        if (root == nullptr) { return; }

        stack<Node<T> *> nps;
        auto t = root;

        while (t != nullptr || !nps.empty()) {
            if (t != nullptr) {
                cout << " " << t->data;
                nps.push(t);
                t = t->left;
            } else {
                t = nps.top();
                nps.pop();
                t = t->right;
            }
        }
    }
    // 3.2 : Inorder
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
    // 3.3 : Postorder
    void iPostorder () {
        if (root == nullptr) { return; }

        Node<T> * t = root;
        Node<T> * last_visited;
        stack<Node<T> *> nps;

        while (t != nullptr || !nps.empty()) {
            if (t != nullptr) {
                nps.push(t);
                t = t->left;
            } else {
                auto to_ckeck = nps.top();

                if (to_ckeck->right == nullptr || to_ckeck->right == last_visited) {
                    cout << ' ' << to_ckeck->data;
                    last_visited = to_ckeck;
                    nps.pop();
                } else {
                    t = to_ckeck->right;
                }
            }
        }
    }
    // 3.4 : levelorder
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



    // 4-7 : Tree Statistics using Recursion

    // 4 : count
    int noNodes () { return nn(root); }
    int nn(Node<T> * u) {
        if (u == nullptr) { return 0;}

        int x = nn(u->left);
        int y = nn(u->right);

        return x + y + 1;
    }
    // 5 : sum
    T sumNodes () { return sn(root); }
    T sn(Node<T> *u) {
        if (u == nullptr) { return T(); }

        T x = sn(u->left);
        T y = sn(u->right);

        return x + y + u->data;
    }
    // 6 : count with degree
    // 6.1 : degree zero
    int noZeroDegree () { return nzd(root); }
    int nzd (Node<T> * u) {
        if (u == nullptr) { return 0; }

        int x = nzd(u->left);
        int y = nzd(u->right);

        if (u->left == nullptr && u->right == nullptr) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    // 6.2 : degree one
    int noOneDegree () { return nod(root); }
    int nod (Node<T> * u) {
        if (u == nullptr) { return 0; }

        int x = nod(u->left);
        int y = nod(u->right);

        if ((u->left == nullptr) ^ (u->right == nullptr)) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    // 6.3 : degree two
    int noTwoDegree () { return ntd(root); }
    int ntd (Node<T> * u) {
        if (u == nullptr) { return 0; }

        T x = ntd(u->left);
        T y = ntd(u->right);

        if ((u->left != nullptr) && (u->right != nullptr)) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    // 6.4 : number of nullptrs
    int noNullptr () { return null(root);  }
    int null(Node<T> * u) {
        if (u == nullptr) { return 1;}

        int x = null(u->left);
        int y = null(u->right);

        return x + y;
    }

    // 7 : hight
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

    cout << "Creation" << endl;
    cout << "\n1. Creating Binary Tree" << endl;
    t.createTree();



    cout << "\n\nTraversals" << endl;
    cout << "\n2 : recursive Traversals" << endl;

    cout << "2.1 : Preorder " << endl;
    cout << "Data :";
    t.preorder();

    cout << "2.2 : Inorder " << endl;
    cout << "Data :";
    t.inorder();

    cout << "2.3 : Postorder " << endl;
    cout << "Data :";
    t.postorder();

    cout << "2.4 : Levelorder " << endl;
    t.levelorder();


    cout << "\n3 : Iterative Traversals" << endl;

    cout << "3.1 : Preorder" << endl;
    cout << "Data :";
    t.iPreorder();

    cout << "3.2 : Inorder " << endl;
    cout << "Data :";
    t.iInorder();

    cout << "3.3 : Postorder " << endl;
    cout << "Data :";
    t.iPostorder();

    cout << "3.4 : Levelorder " << endl;
    t.levelorder();



    cout << "\n\nTree Statistics" << endl;

    cout << "\n4 : Count of Nodes" << endl;
    cout << "Count : " << t.noNodes() << endl;

    cout << "\n5 : Sum of Nodes" << endl;
    cout << "Sum : " << t.sumNodes() << endl;

    cout << "\n6 : Count of Nodes with Degree" << endl;

    cout << "6.1 : Degree Zero" << endl;
    cout << "Count : " << t.noZeroDegree() << endl;

    cout << "6.2 : Degree One" << endl;
    cout << "Count : " << t.noOneDegree() << endl;

    cout << "6.3 : Degree Two" << endl;
    cout << "Count : " << t.noTwoDegree() << endl;

    cout << "6.4 : Count of nullptrs" << endl;
    cout << "Count : " << t.noNullptr() << endl;

    cout << "\n7 : Height of Tree" << endl;
    cout << "Hight : " << t.hight() << endl;



    cout << "\n8. Creating Binary Tree from Preorder + Inorder" << endl;

    vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    cout << "Preorder :";
    for (auto x : pre) { cout << ' ' << x; }
    cout << endl;
    vector<int> in = {4, 2, 5, 1, 6, 3, 7};
    cout << "Inorder  :";
    for (auto x : in) { cout << ' ' << x; }
    cout << endl;
    Tree<int> t2;
    t2.createTreeFromTraversal(pre, in);

    cout << "Created Tree from Traversal" << endl;
    t2.preorder();

    return 0;
}
