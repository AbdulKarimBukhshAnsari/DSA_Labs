#include<iostream>
using namespace std ;
class custom_circular_queue{
    int *array;
    int front;
    int rear;
    int size;
    int count;
    public:
    custom_circular_queue(){
        size = 10;
        array = new int[size];
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isFull(){
        if(rear==((front+1)%size)){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(front==-1){
            return true;
        }
        return false;
    }

    void enqueue(int element){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
            return ;
        }
        if(front == -1){
            front =0;
        }
        rear = (rear+1)%size;
        array[rear] = element;
        count++;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int result = array[front];
        if(front==rear) front = rear = -1;
        else{
        front = (front+1)%size;
        }
        count--;
        return result;
    }

    int size_queue(){
        return count;
    }

    void display(){
        int index = front;
        for(int i = 0 ; i<count ; i++){
            cout<<array[index]<<" ";
            index = (index+1) %size;
        }
    }

    ~custom_circular_queue(){
        delete[] array;
    }
};

int main() {
    custom_circular_queue q; 
    int choice, element;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Get Queue Size\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: // Enqueue
                cout << "Enter the element to enqueue: ";
                cin >> element;
                q.enqueue(element);
                break;
            
            case 2: // Dequeue
                element = q.dequeue();
                if (element != -1)
                    cout << "Dequeued element: " << element << endl;
                break;

            case 3: // Display
                cout << "Queue contents: ";
                q.display();
                break;

            case 4: // Get 
                cout << "Current queue size: " << q.size_queue() << endl;
                break;

            case 5: 
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 5);

    return 0;
}
