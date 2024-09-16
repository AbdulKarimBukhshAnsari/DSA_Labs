#include<iostream>
#include"Abdul_Karim_Lab3.cpp"
using namespace std;
// Making main function 
int main(){
    Abdul_Karim_Lab03 fibo("int");
    int num; 
    cout<<"Enter the number to which you need fibonacci series: ";
    cin>>num;
    int first = 0;
    int second = 1;
    fibo.push(first) ; fibo.push(second);
    for(int i = 0 ;i<num-2 ; i++){
        fibo.push(first+second);
        int temp = second ;
        second = first+second;
        first = temp;
    
    }
    fibo.reverse();
    
}