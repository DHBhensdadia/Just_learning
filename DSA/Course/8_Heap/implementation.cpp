#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

template<typename T>
class Heap {
    vector<T> av;

public:
    // constructors
    Heap () {}


    // Operations on heap (Max Heap)

    // 1. Insertion
    void insert (T val) {
        int index = av.size();
        av.push_back(val);

        for (int i = index; i > 0; i = (i-1)/2) {
            int j = (i-1) / 2;
            if (av[j] > av[i]) {
                break;
            }
            swap(av[j], av[i]);
        }
    }

    // 2. Creation
    void create (vector<T> val) {
        for (int i = val.size() - 1; i >= 0; i--) {
            insert(val[i]);
        }
    }

    // 3. Deletion
    T delete_ () {
        int size = av.size();
        if (size == 0) {
            return 0;
        }
        T root = av[0];

        av[0] = av[size-1];
        av.pop_back();
        size--;

        int cur = 0;
        int lc = 1;
        int rc = 2;

        while (1) {
            int target;
            if (rc < size) {
                if (av[lc] < av[rc]) {
                    target = rc;
                } else {
                    target = lc;
                }
            } else if (lc < size) {
                target = lc;
            } else {
                break;
            }

            if (av[target] > av[cur]) {
                swap(av[target], av[cur]);
                cur = target;
                lc = (target+1)*2 - 1;
                rc = (target+1)*2;
            } else {
                break;
            }
        }

        return root;
    }

    // 4. Heapify
    void heapify (vector<T> in) {
        int size = in.size();
        if(size == 0) {
            av = in;
            return;
        }

        av = in;

        for (int j = in.size(); j > 0; j--) {
            int cur = j - 1;
            int lc = j * 2 - 1;
            int rc = j * 2;

            while (1) {
                int target;
                if (rc < size) {
                    if (av[lc] < av[rc]) {
                        target = rc;
                    } else {
                        target = lc;
                    }
                } else if (lc < size) {
                    target = lc;
                } else {
                    break;
                }

                if (av[target] > av[cur]) {
                    swap(av[target], av[cur]);
                    cur = target;
                    lc = (target+1)*2 - 1;
                    rc = (target+1)*2;
                } else {
                    break;
                }
            }
        }
    }
};

template<typename T>
vector<T> heap_sort(vector<T> in) {
    Heap<T> h;

    int size = in.size();
    for (auto i : in) {
        h.insert(i);
    }

    vector<T> ans;
    for (int i = 0; i < size; i++) {
        ans.push_back(h.delete_());
    }

    return ans;
}

int main () {
    cout << "Creation" << endl;
    cout << "\n1. Inserting into Heap (via Heap Sort)" << endl;

    vector<int> arr = {10, 20, 15, 30, 40};
    cout << "Input Array :";
    for (int x : arr) cout << " " << x;
    cout << endl;



    cout << "\n\nOperations" << endl;
    cout << "\n2 : Executing Heap Sort (Tests Insert and Delete)" << endl;

    vector<int> sorted = heap_sort(arr);

    cout << "2.1 : Output from Heap Sort " << endl;
    cout << "Data :";
    for (int x : sorted) cout << " " << x;
    cout << endl;



    cout << "\n\nHeapify" << endl;
    cout << "\n3 : Executing Heapify" << endl;

    Heap<int> h;
    vector<int> to_heapify = {50, 60, 45, 70, 80};
    cout << "Input Array :";
    for (int x : to_heapify) cout << " " << x;
    cout << endl;

    h.heapify(to_heapify);

    cout << "3.1 : Deleting max from Heapified array " << endl;
    cout << "Data : " << h.delete_() << endl;

    return 0;
}
