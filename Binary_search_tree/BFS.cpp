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
    
    void LevelOrder(BST *);
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

void BST :: LevelOrder(BST *root) {
    if(!root) return;
    queue<BST*> Q;
    Q.push(root);
    while (!Q.empty()) {
        BST* current = Q.front();
        cout << current->data << " ";
        if (current->left != nullptr) Q.push(current->left);
        if (current->right != nullptr) Q.push(current->right);
        Q.pop();
    }
    cout << endl;
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
    b.LevelOrder(root);
    return 0;
}
