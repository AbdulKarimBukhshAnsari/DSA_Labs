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

    int sumOfNodes(Node* node) {
        if (node == nullptr) {
            return 0;  // Base case: if the node is null, its contribution is 0
        }
        // Recursively calculate the sum of left and right subtrees and add the current node's value
        return node->value + sumOfNodes(node->left) + sumOfNodes(node->right);
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
};

int main() {
    BinarySearchTree bst;

    // Inserting nodes into the Binary Search Tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Calculating the sum of all nodes
    int sum = bst.sumOfNodes(bst.root);

    // Printing the result
    cout << "The sum of all nodes in the BST is: " << sum << endl;

    return 0;
}
