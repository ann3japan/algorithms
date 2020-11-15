#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* link;
};

class Stack {
public:
    Node* top = nullptr;
    
    void push(int val) {
        Node* tmp = new Node;
        tmp->data = val;
        tmp->link = top;
        top = tmp;
    }
    
    void pop() {
        Node* tmp = top;
        if (top == nullptr) return;
        top = top->link;
        free(tmp);
    }
};

int main() {
    
    return 0;
}
