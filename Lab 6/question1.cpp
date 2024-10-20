#include<iostream>
using namespace std;

class custom_queue{
    int *array ;
    int front;
    int rear;
    int size;
    public:
    custom_queue(){
        size = 100;
        array = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        if(front== -1){
            return true;
        }
        return false;
    }
    
    bool isFull(){
        if(rear== size -1){
            return true;
        }
        return false;
    }

    void enque(int element){
        if(isFull()){
            cout<<"Queue is Full";
            return;
        }
        if(front==-1) front = 0;
        rear = rear+1;
        array[rear] = element;
    }

    int deque(){
        if(isEmpty()){
            cout<<"Queue is full";
            return -1;
        }
        int result ;
        if(front== rear){
            front = rear = -1;
        }
        else{
            result = array[front];
            array[front] = -1;
            front++;
        }
        return result;
    
    }

    void display(){
        for(int i = front ; i<=rear ;i++){
            cout<<array[i]<<" ";
        }
    } 
    ~custom_queue(){
        delete[] array;
    }
    
};

int main() {
    custom_queue q; 
    int choice, element;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: 
                cout << "Enter the element to enqueue: ";
                cin >> element;
                q.enque(element);
                break;
            case 2: 
                element = q.deque();
                if (element != -1)
                    cout << "Dequeued element: " << element << endl;
                break;
            case 3: 
                cout << "Queue contents: ";
                q.display();
                break;
            case 4: 
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);
    return 0;
}

