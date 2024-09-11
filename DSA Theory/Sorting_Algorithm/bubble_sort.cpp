#include<iostream>
using namespace std;

void bubble_sort_custom(int arr[6],int n){
    bool check = false;
    // The last will be sorted automatically if the all reaining wil be sorted so we will try to do 1 less comparison
    for(int i = 0 ; i<n-1;i++){
        // As we know that after each comparison the last element will be sorted so in each iteraion we wil change the condition of last by less than 1
        for(int j = 0 ;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                check = true;
            }               
        }
        if(check == false) break;
        else check = false;
    }
    return ;
}

int main(){
    int arr[6] = {1,0,78,45,9,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort_custom(arr,size);
    for(int i = 0 ; i<6;i++){
        cout<<arr[i]<<" ";
    }
}