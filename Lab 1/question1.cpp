#include<iostream>
using namespace std;
int main(){
    int rows,columns ;
    cout<<"Enter the rows and column of the array: ";
    cin>>rows>>columns;
    cout<<"Enter the elements for the 2d array: "<<endl;
    int arr[rows][columns] ;
    for(int i =0;i<rows;i++){
        for(int j=0;j<rows;j++){
            cin>>arr[i][j];
        }
    }
    int res[rows*columns];
    int k=0;
    for(int i =0;i<rows;i++){
        for(int j = 0;j<columns;j++){
            res[k] = arr[j][i];
            k++;
        }
    }
    // Printing the result
    for(int i =0;i<rows*columns;i++){
        cout<<res[i]<<" , ";
    }

}