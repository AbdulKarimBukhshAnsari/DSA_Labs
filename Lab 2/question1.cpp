#include<iostream>
#include<vector>
using namespace std;
class Matrix{
    public:
    // This function will return bool values 1 for if the value is in the list otherwise 0
    bool binary_search(vector<vector<int>> array,int rows,int cols, int key){
        int start = 0;
        int end = rows*cols -1;
        while(start<=end){
            int mid_index = (start +end)/2;
            int mid_value = array[mid_index/cols][mid_index%cols];
            if(mid_value==key){
                return true;
            }
            else if(mid_value>key){
                end = mid_index-1;
            }
            else{
                start = mid_index+1;
            }
        }
        return false;
    }
};

int main(){
    Matrix matrix;
    int rows, cols;
    cout<<"Enter number of rows and columns: ";
    cin>>rows>>cols;
    vector<vector<int>>  v(rows,vector<int>(cols));
    // Taking input of the vectors elements
    cout<<"Enter the elements: "<<endl;
    for(int i = 0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int temp;
            cin>>temp;
            v[i][j] = temp;
        }
    }
    int key ;
    cout<<"Enter the valuse which you want to check : ";
    cin>>key;
    cout<<matrix.binary_search(v,rows,cols,key);
}