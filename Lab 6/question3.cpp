#include <iostream>
using namespace std;

class Deque {
    int* array;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque(int cap) {
        capacity = cap;
        array = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~Deque() {
        delete[] array;
    }

    void insertFront(int element) {
        if (size == capacity) {
            cout << "Deque is Full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        array[front] = element;
        size++;
    }

    void insertRear(int element) {
        if (size == capacity) {
            cout << "Deque is Full" << endl;
            return;
        }
        if (rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        array[rear] = element;
        size++;
    }

    int deleteFront() {
        if (isEmpty()) {
            cout << "Deque is Empty" << endl;
            return -1;
        }
        int result = array[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return result;
    }

    int deleteRear() {
        if (isEmpty()) {
            cout << "Deque is Empty" << endl;
            return -1;
        }
        int result = array[rear];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
        return result;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty" << endl;
            return;
        }
        cout << "Deque elements: ";
        for (int i = 0; i < size; i++) {
            cout << array[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5);
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(30);
    dq.insertFront(40);
    
    dq.display();
    cout << "Deleted from front: " << dq.deleteFront() << endl;
    cout << "Deleted from rear: " << dq.deleteRear() << endl;

    dq.display();
    cout << "Current size: " << dq.getSize() << endl;

    return 0;
}
