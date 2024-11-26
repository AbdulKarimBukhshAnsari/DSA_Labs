#include <iostream>
using namespace std;

// Node structure for the circular linked list
class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Circular Queue class
class CircularQueue {
private:
    Node* front;  // Points to the front node of the queue
    Node* rear;   // Points to the rear node of the queue

public:
    CircularQueue() {
        front = rear = nullptr;
    }

    // Enqueue operation to add an element to the circular queue
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (front == nullptr) {
            // If the queue is empty, initialize front and rear to the new node
            front = rear = newNode;
            rear->next = front; // Point rear's next to front to make it circular
        } else {
            // Add new node at the end and update rear
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Make it circular
        }
        cout << "Enqueued " << value << endl;
    }

    // Dequeue operation to remove an element from the circular queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty, cannot dequeue." << endl;
            return;
        }

        if (front == rear) {
            // If there's only one element, set both front and rear to null
            cout << "Dequeued " << front->data << endl;
            delete front;
            front = rear = nullptr;
        } else {
            // Remove the front node and update front
            Node* temp = front;
            front = front->next;
            rear->next = front; // Update rear's next to new front
            cout << "Dequeued " << temp->data << endl;
            delete temp;
        }
    }

    // Display all elements in the queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front); // Stop when we loop back to the front
        cout << endl;
    }
};

int main() {
    CircularQueue queue;
    int choice, value;

    while (true) {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
