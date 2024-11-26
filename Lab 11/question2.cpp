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

    Node* findLCA(Node* root, int n1, int n2) {
        if (!root) return nullptr;

        if (root->value > n1 && root->value > n2)
            return findLCA(root->left, n1, n2);
        if (root->value < n1 && root->value < n2)
            return findLCA(root->right, n1, n2);

        return root;
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

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    int n1 = 20, n2 = 40;
    Node* lca = bst.findLCA(bst.root, n1, n2);
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->value << endl;
    else
        cout << "LCA not found!" << endl;

    return 0;
}
