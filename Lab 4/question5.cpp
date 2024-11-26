#include <iostream>
#include <vector>
#include "Abdul_Karim_Lab4.cpp" 

int main(){
    int size;
    cout<<"Enter the size of the array. ";
    cin>>size;
    vector<int> array(size);
    cout<<"Enter the elements for your array:\nWhere 0 represents red\n1 represents white\n2 represents blue.\n";
    for(int i = 0;i<array.size();i++){
        cin>>array[i];
    }
    cout<<"The sorted array is : ";
    Abdul_Karim_Lab04 arr(array);
    arr.bubble_sort_custom();
    for(int i = 0 ;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    return 0 ;
}