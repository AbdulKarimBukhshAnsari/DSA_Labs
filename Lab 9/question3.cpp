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

// Double-ended Queue (Deque) class
class Deque {
private:
    Node* front; // Points to the front of the deque
    Node* rear;  // Points to the rear of the deque

public:
    Deque() {
        front = rear = nullptr;
    }

    // Insert element at the front of the deque
    void insertFront(int value) {
        Node* newNode = new Node(value);

        if (front == nullptr) {
            // If the deque is empty, initialize front and rear to the new node
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "Inserted " << value << " at front" << endl;
    }

    // Insert element at the rear of the deque
    void insertRear(int value) {
        Node* newNode = new Node(value);

        if (rear == nullptr) {
            // If the deque is empty, initialize front and rear to the new node
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Inserted " << value << " at rear" << endl;
    }

    // Delete element from the front of the deque
    void deleteFront() {
        if (front == nullptr) {
            cout << "Deque is empty, cannot delete from front." << endl;
            return;
        }

        Node* temp = front;
        cout << "Deleted " << front->data << " from front" << endl;

        if (front == rear) {
            // If there's only one element
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
    }

    // Delete element from the rear of the deque
    void deleteRear() {
        if (rear == nullptr) {
            cout << "Deque is empty, cannot delete from rear." << endl;
            return;
        }

        Node* temp = rear;
        cout << "Deleted " << rear->data << " from rear" << endl;

        if (front == rear) {
            // If there's only one element
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
    }

    // Display all elements in the deque from front to rear
    void display() {
        if (front == nullptr) {
            cout << "Deque is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Deque elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque deque;
    int choice, value;

    while (true) {
        cout << "\nDouble-ended Queue (Deque) Operations:\n";
        cout << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                deque.insertFront(value);
                break;
            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                deque.insertRear(value);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                deque.display();
                break;
            case 6:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
