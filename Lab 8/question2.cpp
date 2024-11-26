#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;  
        top = newNode;      
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;      
        cout << "Popped " << temp->data << " from the stack." << endl;
        delete temp;         
    }
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; 
        }
        return top->data;
    }

    
    bool isEmpty() const {
        return top == nullptr;
    }

    
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element is: " << stack.peek() << endl;
    stack.display();
    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;
    stack.display();
    return 0;
}
