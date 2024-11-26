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
    void add(int value) {
        root = insert(root, value);
    }
    bool search(int value) {
        return searchNode(root, value);
    }
    void preOrderTraversal() {
        preOrder(root);
        cout << endl;
    }

    void postOrderTraversal() {
        postOrder(root);
        cout << endl;
    }

private:
 
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
        if (value < node->value)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

 
    bool searchNode(Node* node, int value) {
        if (node == nullptr)
            return false;
        if (node->value == value)
            return true;
        if (value < node->value)
            return searchNode(node->left, value);
        else
            return searchNode(node->right, value);
    }

    
    void preOrder(Node* node) {
        if (node == nullptr)
            return;
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

  
    void postOrder(Node* node) {
        if (node == nullptr)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << " ";
    }
};

// Main function
int main() {
    BinaryTree tree;
    tree.add(50);
    tree.add(30);
    tree.add(70);
    tree.add(20);
    tree.add(40);
    tree.add(60);
    tree.add(80);
    int searchValue = 40;
    if (tree.search(searchValue))
        cout << "Value " << searchValue << " found in the tree." << endl;
    else
        cout << "Value " << searchValue << " not found in the tree." << endl;
    cout << "Pre-order Traversal: ";
    tree.preOrderTraversal();
    cout << "Post-order Traversal: ";
    tree.postOrderTraversal();
    return 0;
}
