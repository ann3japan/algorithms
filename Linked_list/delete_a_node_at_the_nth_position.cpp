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
    
    void delete_at_the_nth_position (int n) {
        Node* tmp = head;
        if (!n) {
            head = tmp->link;
            free(tmp);
        }
        for (int i = 0; i < n-1; ++i)
            tmp = tmp->link;
        Node* tmp2 = tmp->link;
        tmp->link = tmp2->link;
        free(tmp2);
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
    l.delete_at_the_nth_position(2);
    l.show();
    return 0;
}
