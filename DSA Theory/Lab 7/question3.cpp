#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MinHeapPriorityQueue {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void push(int element) {
        minHeap.push(element);
    }

    void pop() {
        if (!minHeap.empty()) {
            minHeap.pop();
        } else {
            cout << "Min-Heap is empty." << endl;
        }
    }

    int top() {
        if (!minHeap.empty()) {
            return minHeap.top();
        } else {
            cout << "Min-Heap is empty." << endl;
            return -1;
        }
    }

    bool empty() {
        return minHeap.empty();
    }
};


class MaxHeapPriorityQueue {
public:
    priority_queue<int> maxHeap;

    void push(int element) {
        maxHeap.push(element);
    }

    void pop() {
        if (!maxHeap.empty()) {
            maxHeap.pop();
        } else {
            cout << "Max-Heap is empty." << endl;
        }
    }

    int top() {
        if (!maxHeap.empty()) {
            return maxHeap.top();
        } else {
            cout << "Max-Heap is empty." << endl;
            return -1;
        }
    }

    bool empty() {
        return maxHeap.empty();
    }
};

int main() {
    MinHeapPriorityQueue minHeapQueue;
    MaxHeapPriorityQueue maxHeapQueue;

    int choice, element;

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Insert into Min-Heap\n";
        cout << "2. Remove from Min-Heap\n";
        cout << "3. Get top of Min-Heap\n";
        cout << "4. Insert into Max-Heap\n";
        cout << "5. Remove from Max-Heap\n";
        cout << "6. Get top of Max-Heap\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert into Min-Heap: ";
                cin >> element;
                minHeapQueue.push(element);
                break;
            case 2:
                cout << "Removing top element from Min-Heap.\n";
                minHeapQueue.pop();
                break;
            case 3:
                cout << "Top of Min-Heap: " << minHeapQueue.top() << endl;
                break;
            case 4:
                cout << "Enter element to insert into Max-Heap: ";
                cin >> element;
                maxHeapQueue.push(element);
                break;
            case 5:
                cout << "Removing top element from Max-Heap.\n";
                maxHeapQueue.pop();
                break;
            case 6:
                cout << "Top of Max-Heap: " << maxHeapQueue.top() << endl;
                break;
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
