#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    // We consider the last element as pivot element 
    int pivot = arr[e];
    // We will start with one index less so that we can calculate our work accordingly.
    int i = s-1;
    // We will start loop from the start of the partition and we will movie till one element less than pivot 
    for(int j = s ; j<=e-1 ; j++ ){
        // If the element is less than pivot element that means we have to put those elements before the pivot so we will peroform swapping
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        } 
        }
        swap(arr[i+1],arr[e]);   
    return i+1;
}

void quick_sort_custom(int arr[],int s ,int e){
    if (s<e){
        // Making the partition of pivot elements
        int p = partition(arr,s,e);

        // Doing quick sort for the left elements of the pivot 
        quick_sort_custom(arr , s,p-1);

        // Doing Quick sort for the right elements of the pivot

        quick_sort_custom(arr,p+1,e);

    }

}

int main(){
    int arr[6] = {0,45,2,6,-1,-56};
    quick_sort_custom(arr,0,5);
     for(int i = 0 ; i<6;i++){
        cout<<arr[i]<<" ";
    }

}