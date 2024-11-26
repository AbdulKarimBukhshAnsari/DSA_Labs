#include <iostream>
using namespace std;

class MyCircularDeque {
    int *deque;
    int front, rear, size, capacity;

public:
    MyCircularDeque(int k) : capacity(k), size(0) {
        deque = new int[capacity];
        front = 0;
        rear = capacity - 1;
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Cannot insert " << value << " at front: Queue is full." << endl;
            return;
        }
        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        size++;
        cout << "Inserted " << value << " at front." << endl;
    }

    void insertLast(int value) {
        if (isFull()) {
            cout << "Cannot insert " << value << " at rear: Queue is full." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        deque[rear] = value;
        size++;
        cout << "Inserted " << value << " at rear." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Cannot delete from front: Queue is empty." << endl;
            return;
        }
        cout << "Deleted " << deque[front] << " from front." << endl;
        front = (front + 1) % capacity;
        size--;
    }

    void deleteLast() {
        if (isEmpty()) {
            cout << "Cannot delete from rear: Queue is empty." << endl;
            return;
        }
        cout << "Deleted " << deque[rear] << " from rear." << endl;
        rear = (rear - 1 + capacity) % capacity;
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. Front item does not exist." << endl;
            return -1;
        }
        cout << "Front item is: " << deque[front] << endl;
        return deque[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty. Rear item does not exist." << endl;
            return -1;
        }
        cout << "Rear item is: " << deque[rear] << endl;
        return deque[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current Queue: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << deque[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    MyCircularDeque myCircularDeque(3);
    myCircularDeque.insertLast(1);
    myCircularDeque.insertLast(2);
    myCircularDeque.insertFront(3);
    myCircularDeque.insertFront(4); // Queue is full, should display a message.
    myCircularDeque.getRear();
    cout << "Is the queue full? " << (myCircularDeque.isFull() ? "Yes" : "No") << endl;
    myCircularDeque.deleteLast();
    myCircularDeque.insertFront(4);
    myCircularDeque.display();
    return 0;
}
