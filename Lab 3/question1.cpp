#include<iostream>
#include"Abdul_Karim_Lab3.cpp"
using namespace std;
int main(){
    string type;
    cout<<"Enter the type of the stack: ";
    cin>>type;
    Abdul_Karim_Lab03 s1(type);
    int size;
    cout<<"How many elements you want to enter in your stack: ";
    cin>>size;
    cout<<"Enter the elements in your stack: ";
    for(int i = 0; i<size;i++){
        int temp;
        cin>>temp;
        s1.push(temp);
    }
    while (true){
        int choice;
        cout<<"Enter which operation you want to perform.\n1)Size of the stack.\n2)Pop the Element.\n3)Display the element of the array.\n4)Enter whether the stack is empty or not.\n5)Write the peek element.\n6))End the operation\n"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            s1.size_func();
            break;
        case 2:
            s1.pop();
            break;
        case 3:
            s1.display();
            break;
        case 4:
            s1.isEmpty();
            break;
        case 5:
            s1.peek();
            break;
        case 6:
            return 0;
        }
        cout<<"--------------------------------------------------------------------------\n";
    }
}