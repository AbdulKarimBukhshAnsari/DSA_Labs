#include <iostream>
using namespace std;

// Node structure for the doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Doubly linked list class
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Add node at the end of the list
    void append(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {  // If list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Concatenate current list with another list
    void concatenate(DoublyLinkedList& otherList) {
        if (head == nullptr) {  // If this list is empty, point head to other list's head
            head = otherList.head;
            tail = otherList.tail;
        } else if (otherList.head != nullptr) {  // If other list is not empty
            tail->next = otherList.head;
            otherList.head->prev = tail;
            tail = otherList.tail;
        }
    }

    // Display the elements of the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList L, M, N;

    // Populate list L with even numbers from 2 to 10
    for (int i = 2; i <= 10; i += 2) {
        L.append(i);
    }
    cout << "List L (even numbers): ";
    L.display();

    // Populate list M with odd numbers from 1 to 9
    for (int i = 1; i < 10; i += 2) {
        M.append(i);
    }
    cout << "List M (odd numbers): ";
    M.display();

    // Concatenate list L and M into list N
    N.concatenate(L);
    N.concatenate(M);

    cout << "Concatenated List N: ";
    N.display();

    return 0;
}
