/*
 Example:
 Input: 1->2->3->4->5->NULL, m = 2, n = 4
 Output: 1->4->3->2->5->NULL
*/

struct Node {
    int data;
    Node* next;
};

class List {
public:
    Node* reverse_between(Node* head, int m, int n) {
        if (!head) return nullptr;
        Node *curr, *prev, *next, *front, *tail;
        curr = head;
        prev = nullptr;
        
        while (m > 1) {
            prev = curr;
            curr = curr->next;
            --n; --m;
        }
        
        front = prev;
        tail = curr;
        
        while (n) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            --n;
        }
        
        if (front != nullptr)
            front->next = prev;
        else
            head = prev;
        tail->next = curr;
        return head;
    }
};
