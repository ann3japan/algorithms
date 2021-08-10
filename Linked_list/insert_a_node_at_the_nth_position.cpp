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
    
    void insert_at_the_nth_position (int x, int n) {
        Node* tmp = new Node;
        tmp->data = x;
        if (!n) {
            tmp->link = head;
            head = tmp;
            return;
        }
        Node* tmp2 = head;
        for (int i = 0; i < n-1; ++i)
            tmp2 = tmp2->link;
        tmp->link = tmp2->link;
        tmp2->link = tmp;
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
    l.insert(4);
    l.insert(5);
    l.insert_at_the_nth_position(6, 3);
    l.show();
    return 0;
}
