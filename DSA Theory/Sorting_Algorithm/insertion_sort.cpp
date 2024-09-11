#include<iostream>
using namespace std;

void insertion_sort_custom(int arr[] , int n){
    // We will consider that the first element will be sorted so we will start outer loop from the i=1 till end 
    for(int i = 1 ; i<n;i++){
        // We will start the value of j = i-1 we will start comparing from the 1 element before the ith element 
        int j = i -1;
        int temp = arr[i];
        while(j>=0 && temp < arr[j] ){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp ;

    }
}

int main(){
    int arr[6] = {56,34,-1,-56,8,104};
    insertion_sort_custom(arr,6);
    for(int i = 0 ; i<6;i++){
        cout<<arr[i]<<" ";
    }
}