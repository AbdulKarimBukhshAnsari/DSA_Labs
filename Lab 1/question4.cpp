#include<iostream>
using namespace std;

int binary_search(int key,int arr[],int size){
    int start = 0;
    int end = size-1;
    while(start<=end){
        int mid = start+((end-start)/2);
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}

int main(){
    int size,key;
    cout<<"Enter the value which you want to find: ";
    cin>>key;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    // Taking input for the array
    for(int i = 0;i<size;i++){
        cin>>arr[i];
    }
    int result = binary_search(key , arr, size);
    cout<<"The result is "<<result;
}