#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* link;
};

class List {
public:
    Node* head = nullptr;
    
    void insert (int x) {
        Node* tmp = new Node;
        tmp->data = x;
        tmp->link = head;
        head = tmp;
    }
    
    void show() {
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->link;
        }
    }
};

int main() {
    List l;
    l.insert(2);
    l.insert(3);
    l.show();
    return 0;
}
