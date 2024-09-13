#include<iostream>
#include"Abdul_Karim_Lab3.cpp"
using namespace std;
int main(){
    string word ;
    cout<<"Enter The word : ";
    cin>>word;
    int n = word.size();
    // Making the instance of the class
    Abdul_Karim_Lab03 string_custom("char",n);
    // Entering the string in the form of  char in the stack 
    for(int i = 0;i<n;i++){
        string_custom.push_char(word[i]);
    }
    // Reversing the string
    char* reverse = string_custom.reverse_string();
    if(string_custom.check_palindrom(reverse)){
        cout<<"The String is Palindrom.";
        return 0;
    }
    else cout<<"String is not palindrom.";
    return 0;

}