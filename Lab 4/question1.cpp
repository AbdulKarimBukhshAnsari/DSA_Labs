#include<iostream>
#include"Abdul_Karim_Lab4.cpp"

int modified_bubble_sort(int arr[30],int n){
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
        if(check == false) return 1;
    }
    return 0 ;
}

int main(){
    int size,arr[30];
    cout<<"Enter the size of the array: ";
    cin>>size;
    cout<<"Enter the Elements: ";
    for(int i = 0; i<size;i++){
        cin>>arr[i];
    }
    int res = modified_bubble_sort(arr,size);
    if(res==1)
    cout<<"The Array is already sorted."<<endl;
    else 
    cout<<"The array has been sorted";
    return 0;
}