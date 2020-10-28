#include <iostream>
//#include <string>
//#include <cmath>
//#include <vector>
//#include <algorithm>
using namespace std;

class quick_union {
private:
    int data[10];
    int size[10];
    int root (int p) {
        if (p != data[p])
            p = data[p];
        return p;
    }
public:
    quick_union () {
        for (int i=0; i<10; ++i) {
            data[i] = i;
            size[i] = 1;
        }
    }
    bool connected (int p, int q) {
        return (root(p) == root(q));
    }
    void union_connection (int p, int q) {
        data[root(q)] = root(p);
    }
    void weighted_qu (int p, int q) {
        if(size[root(p)] < size[root(q)]) {
            data[root(p)] = root(q);
            size[root(q)] += size[root(p)];
        }
        else {
            data[root(q)] = root(p);
            size[root(p)] += size[root(q)];
        }
    }
    void path_compression (int i) {
        int p = i;
        while (p != data[p])
            p = data[p];
        while (i != p)
            swap(data[i], p);
        while (i != data[i]) {
            data[i] = data[data[i]];
            i = data[i];
        }
    }
};

int main() {
    quick_union qu;
    qu.weighted_qu(0, 1);
    qu.weighted_qu(1, 2);
    cout << qu.connected(0, 2);

    return 0;
}


