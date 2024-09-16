#include<iostream>
using namespace std;

class Abdul_Karim_Lab03{
public:

    int size =20;
    int *stack_int ; 
    int top;
    char *stack_char;
    // Defining just for char type stack 
    int capacity;


    // Defining the Constructors
    Abdul_Karim_Lab03(string type){
        if(type=="int" ){
             stack_int = new int[size];
        }
        else if(type == "char"){
            stack_char = new char[size];
        }
        top = -1;
    }
    // For Char
    Abdul_Karim_Lab03(string type , int capacity ){
        stack_char = new char[capacity];
        this->capacity = capacity;
        top = -1;
    }
    // Resizing the stack 
    void resize_stack(){
        int* resizestack = new int[size+5];
        for(int i = 0 ; i<size ;i++){
            resizestack[i] = stack_int[i];
        }
        delete[] stack_int ;
        stack_int = nullptr;
        stack_int = resizestack;
        size+=5;
    }
    // To add the element
    void push(int element){
        if(top>=size-1){
           resize_stack(); 
        }
        top++;
        stack_int[top] = element;
    }
    // To pop the element this is for both the int and char 
    void pop(){
        if(top==-1){
            cout<<"Stack is empty\n";
            return ;
        }
        top--;
    }
    // To display the stack
    void display(){
        for(int i =0 ; i<=top;i++){
            cout<<stack_int[i]<<" ";
        }
        cout<<endl;
    }
    void peek(){
        cout<<"The peek elemeent is "<<stack_int[top];
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

    // Function for question 2
    void push_char(char i){
        if(top>=capacity-1){
            cout<<"Stack overflow.";
            return ;
        }
        top++;
        stack_char[top] =i; 
    }

    void pop_char(){
        if(top==1){
            cout<<"Stack is empty: ";
            return;
        }
        else{
            top--;
        }
    }
    // Displaying the stack
    void display_char(){
        for(int i = 0 ; i<capacity;i++){
            cout<<stack_char[i];
        }
        cout<<endl;
    }
    // Reversing the element 
    char* reverse_string(){
        if(top==-1){
            cout<<"Stack Overflow..";
        }
        else{
            char* reversestring = new char[capacity];
            for(int i = 0 ;i<capacity;i++){
                reversestring[i] = stack_char[top];
                top--; 
            }
            return reversestring;
        }
    }

    bool check_palindrom(char* reverse){
        bool check = true;
        for(int i = 0;i<capacity;i++){
            if(stack_char[i]!=reverse[i]){
                check = false;
            }
        }
        return check ;
    }
    // Function for question 5 reversing the stack;
    Abdul_Karim_Lab03 reverse(){
        Abdul_Karim_Lab03 reverse_fibo("int");
        int end_loop = top;
        for(int i = 0 ; i<=end_loop;i++){
            int temp = stack_int[top];
            pop();
            reverse_fibo.push(temp);
        }
        reverse_fibo.display();
    }
    // Deallocating teh memory 
    ~Abdul_Karim_Lab03(){
        delete[] stack_int;
        delete[] stack_char;
    } 

};

