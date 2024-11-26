#include<iostream>
using namespace std;
class Custom_queue{
    private:

    int size;
    int *arr;
    int front ;
    int rear;
    public:
    Custom_queue(){
        size = 100;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    // to check the condition of empty 
    bool isEmpty(){
        if(front == -1)
        return true;
        return false;
    }

    // To check the condition of the full 
    bool isFull(){
        if(rear == size-1)
        return true;
        return false;
    }
    // To add the elements in the queue
    void enqueue(int element){
        if(isFull()){
            cout<<"Queue is full";
            return ;
        }
        if(front==-1)
            front = 0;
        arr[++rear] = element;
    }
    // To delete the element 
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty ";
            return ;
        }
        cout<<"The element"<<arr[front]<<" has been poped\n";
        if(front==rear){
            front =-1;
            rear = -1;
            return;
            }
        arr[front] =-1;
        front++;
    }
    // Size of the queu
    int size_queue(){
        if(isEmpty()){
            return 0;
        }
        return rear-front+1;
    }
    // front element 
    int front_queue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return ;
        }
        return arr[front];
    }
    // To display the elements of the queue
    void display(){
        for(int i = front  ;i<=rear;i++){
            cout<<arr[i]<<",";
        }
        cout<<endl;
    }
};

