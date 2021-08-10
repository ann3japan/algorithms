#include <iostream>

using namespace std;

struct BstNode {
    int data;
    BstNode* right;
    BstNode* left;
};

class Bst {
public:
    BstNode* get_new_node(int data) {
        BstNode* node = new BstNode;
        node->data = data;
        node->left = node->right = nullptr;
        return node;
    }
    
    BstNode* insert_node(BstNode* root, int data) {
        if (!root) root = get_new_node(data);
        else if (data <= root->data)
            root->left = insert_node(root->left, data);
        else root->right = insert_node(root->right, data);
        return root;
    }
    
    bool search(BstNode* root, int data) {
        if (!root) return false;
        else if (root->data == data) return true;
        else if (data <= root->data) return search(root->left, data);
        else return search(root->right, data);
    }
};

int main() {
    Bst bst;
    BstNode* root = nullptr;
    root = bst.insert_node(root, 8);
    if (bst.search(root, 8) == true) cout << "Found";
    return 0;
}
