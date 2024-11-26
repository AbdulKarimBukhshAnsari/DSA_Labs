#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void preorderTraversal() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorderTraversal() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

private:
    Node* insertNode(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
        if (value < node->value)
            node->left = insertNode(node->left, value);
        else if (value > node->value)
            node->right = insertNode(node->right, value);
        return node;
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->value << " ";
        }
    }
};

int main() {
    BinarySearchTree bst;

    cout << "Inserting nodes into the Binary Search Tree..." << endl;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.preorderTraversal();
    bst.postorderTraversal();

    cout << "\nInserting some additional nodes..." << endl;
    bst.insert(90);
    bst.insert(10);

    bst.preorderTraversal();
    bst.postorderTraversal();

    return 0;
}
