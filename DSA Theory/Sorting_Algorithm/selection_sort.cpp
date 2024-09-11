#include<iostream>
using namespace std;

void selection_sort_custom(int arr[],int n){
    for(int i = 0 ;i<n-1;i++){
        // Considering that first element is the samllest element in the list 
        int min = i;
        // We know that till i the element will already be sorted , so we will start to compare from i+1
        for(int j = i+1;j<n;j++){
            if(arr[min]>arr[j]) 
            min = j;
        }
        swap(arr[min] ,arr[i]);
    }
}

int main(){
    int arr[6] = {90,56,105,10,0,105};
    selection_sort_custom(arr,6);
    for(int i = 0 ; i<6;i++){
        cout<<arr[i]<<" ";
    }
}