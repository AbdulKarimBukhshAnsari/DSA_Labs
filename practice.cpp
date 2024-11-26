#include<iostream>
using namespace std;
int main(){
    int arr[6] = {34,56,1,2,78,56};
    bool condi = false;
    for(int i =0 ; i<6-1;i++){
        for(int j = 0 ;j<6-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                condi = true;
            }
        }
        if(condi== false) break;
        else {
            condi = false;
        }
    }

}