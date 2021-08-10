struct Node {
    int data;
    Node* next;
};

class List {
public:
    Node* recursion(Node* head, Node* prev) {
        if (!head) return prev;
        Node* next = head->next;
        head->next = prev;
        return recursion(next, head);
    }
    
    Node* reverseList(Node* head) {
        return recursion(head, nullptr);
    }
};
