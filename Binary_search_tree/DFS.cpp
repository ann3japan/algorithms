#include <iostream>
#include <queue>
using namespace std;

class BST {
    char data;
    BST *left, *right;
public:
    BST() : data(0), left(nullptr), right(nullptr) {}
    BST(int);
    BST* Insert(BST *, char);
    
    void PreOrder(BST *);
    void InOrder(BST *);
    void PostOrder(BST *);
};

BST :: BST(int value) {
    data = value;
    left = right = nullptr;
}

BST* BST :: Insert(BST *root, char value) {
    if(!root) return new BST(value);
    
    if(value > root->data)
        root->right = Insert(root->right, value);
    
    else root->left = Insert(root->left, value);
    
    return root;
}

void BST::PreOrder(BST *root) {
    if (!root) return;
    PreOrder(root->left);
    cout << root->data;
    PreOrder(root->right);
}

void BST::InOrder(BST *root) {
    if (!root) return;
    InOrder(root->left);
    InOrder(root->right);
    cout << root->data;
}

void BST::PostOrder(BST *root) {
    if (!root) return;
    cout << root->data;
    PostOrder(root->left);
    PostOrder(root->right);
}

int main() {
    BST b, *root = nullptr;
    root = b.Insert(root, 'A');
    b.Insert(root, 'B');
    b.Insert(root, 'C');
    b.Insert(root, 'D');
    b.Insert(root, 'E');
    b.Insert(root, 'F');
    b.Insert(root, 'G');
    b.Insert(root, 'H');
    b.PostOrder(root);
    return 0;
}
