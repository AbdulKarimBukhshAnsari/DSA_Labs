#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a Linked List Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "None" << endl;
}

// Function to sort the linked list in descending order
Node* sortLinkedListDescending(Node* head) {
    // Step 1: Extract elements into a vector
    vector<int> elements;
    Node* current = head;
    while (current != nullptr) {
        elements.push_back(current->data);
        current = current->next;
    }

    // Step 2: Sort the vector in descending order
    sort(elements.begin(), elements.end(), greater<int>());

    // Step 3: Rebuild the linked list with sorted elements
    Node* sortedHead = nullptr;
    Node* temp = nullptr;

    for (int elem : elements) {
        Node* newNode = new Node(elem);
        if (!sortedHead) {
            sortedHead = newNode;
        } else {
            temp = sortedHead;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    return sortedHead;
}

int main() {
    // Create a linked list with numbers from 1 to 9
    Node* N = new Node(1);
    Node* current = N;
    for (int i = 2; i <= 9; ++i) {
        current->next = new Node(i);
        current = current->next;
    }

    cout << "Original Linked List: ";
    printLinkedList(N);

    // Sort the linked list in descending order
    Node* sortedList = sortLinkedListDescending(N);

    cout << "Sorted Linked List in Descending Order: ";
    printLinkedList(sortedList);

    return 0;
}
