#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void setRoot(Node* node) {
        root = node;
    }

    bool isSymmetric() {
        if (!root)
            return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(Node* left, Node* right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->value != right->value)
            return false;
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};

int main() {
    BinaryTree tree;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    tree.setRoot(root);

    cout << "Checking symmetry for a predefined tree..." << endl;

    if (tree.isSymmetric())
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    BinaryTree nonSymmetricTree;
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(2);
    root2->left->right = new Node(3);
    root2->right->right = new Node(3);

    nonSymmetricTree.setRoot(root2);

    cout << "\nChecking symmetry for another predefined tree..." << endl;

    if (nonSymmetricTree.isSymmetric())
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    return 0;
}
