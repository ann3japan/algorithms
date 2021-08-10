struct Node {
    int data;
    Node* link;
};

class List {
public:
    Node* reverseList(Node* head) {
        Node* curr, *prev, *next;
        prev = nullptr;
        curr = head;
        while (curr != nullptr) {
            next = curr->link;
            curr->link = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
