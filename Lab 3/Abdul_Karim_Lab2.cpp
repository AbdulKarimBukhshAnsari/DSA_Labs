#include<iostream>
using namespace std;

class Abdul_Karim_Lab2{

private:
    int size;
    int stack[100];
    int top;

public:
    Abdul_Karim_Lab2(int capacity){
        size = capacity;
        top = -1;
    }
    // To add the element
    void push(int element){
        if(top>=size-1){
            cout<<"Stack Overflow..\n";
            return;
        }
        top++;
        stack[top] = element;
    }
    // To pop the element
    void pop(){
        if(top==-1){
            cout<<"Stack is empty\n";
            return ;
        }
        top--;
        cout<<"Succesfully poped the element\n"<<endl;
    }
    // To display the stack
    void display(){
        for(int i =0 ; i<=top;i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }

    // Checking if the stack is empty or not
    void isEmpty(){
        if(top==-1){
            cout<<"Stack is Empty\n";
            return ;
        }
        cout<<"Stack is not Empty\n";
    }
    //Size of the stack

    void size_func(){
        cout<<"The size of the stack is "<<top+1<<"\n";
    } 

};