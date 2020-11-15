#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* link;
};

class Queue {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    bool is_empty () {
        return head == nullptr && tail == nullptr;
    }
    void enqueue (int value) {
        Node* ptr = new Node();
        ptr->data = value;
        ptr->link = nullptr;
        if (head == nullptr) {
            head = ptr;
            tail = ptr;
        }
        else {
            tail->link = ptr;
            tail = ptr;
        }
    }
    void dequeue () {
        if (is_empty()) cout << "already empty";
        else if (head == tail) {
            free(head);
            head = tail = nullptr;
        }
        else {
            Node* ptr = head;
            head = head->link;
            free(ptr);
        }
    }
    void show () {
        if (is_empty()) cout << "already empty";
        else {
            Node* ptr = head;
            while (ptr != nullptr) {
                cout << ptr->data << " ";
                ptr = ptr->link;
            }
        }
    }
};

int main() {
    Queue qu;
    qu.enqueue(4);
    qu.enqueue(5);
    qu.dequeue();
    qu.show();
    return 0;
}
