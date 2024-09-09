#include<iostream>
#include"Abdul_Karim_Lab2.cpp"
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of the stack: ";
    cin>>size;
    Abdul_Karim_Lab2 s1(size);
    cout<<"Enter the elements in your stack: ";
    for(int i = 0; i<size;i++){
        int temp;
        cin>>temp;
        s1.push(temp);
    }
    while (true){
        int choice;
        cout<<"Enter which operation you want to perform.\n1)Size of the stack.\n2)Pop the Element.\n3)Display the element of the array.\n4)Enter whether the stack is empty or not.\n5)End the operation"<<endl;
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
            return 0;
        }
        cout<<"--------------------------------------------------------------------------\n";
    }
}