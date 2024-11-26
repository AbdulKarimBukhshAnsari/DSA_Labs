#include <iostream>
using namespace std;

// Definition for singly-linked list node.
class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Function to delete duplicates from sorted linked list
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head;
    
    // Traverse the list
    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            // Duplicate found, skip the next node
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;  // Free the memory of the duplicate node
        } else {
            // Move to the next node
            current = current->next;
        }
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Helper function to insert a new node at the end of the list
void insertNode(ListNode*& head, int val) {
    if (head == nullptr) {
        head = new ListNode(val);
        return;
    }
    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = new ListNode(val);
}

int main() {
    // Create a sorted linked list with duplicates
    ListNode* head = nullptr;
    insertNode(head, 1);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 3);

    cout << "Original list: ";
    printList(head);

    // Remove duplicates
    head = deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
