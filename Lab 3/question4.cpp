#include<iostream>
#include"Abdul_Karim_Lab3.cpp"
using namespace std;

string remove_backspace(Abdul_Karim_Lab03 &word, int size) {
    Abdul_Karim_Lab03 temp("char", size);
    for (int i = 0; i < size; i++) {
        if (word.stack_char[i] == '#') {
            temp.pop_char();  
        } else {
            temp.push_char(word.stack_char[i]);  
        }
    }

    string result = "";
    for (int i = 0; i <= temp.top; i++) {
        result += temp.stack_char[i]; 
    }
    
    return result;  
}
int main(){
    string str1,str2;
    cout<<"Enter 1st sting: ";
    cin>>str1;
    cout<<"Enter 2nd string: ";
    cin>>str2;
    int n1 = str1.size();
    int n2 = str2.size();
    // Making instances of the String
    Abdul_Karim_Lab03 word1("char",n1);
    Abdul_Karim_Lab03 word2("char",n2);
    for (int i = 0; i < n1; i++) {
        word1.push_char(str1[i]);
    }
    for (int i = 0; i < n2; i++) {
        word2.push_char(str2[i]);
    }
    string result1 =remove_backspace(word1,n1);
    string result2 = remove_backspace(word2,n2);
    if(result1==result2) cout<<true;
    else  cout<<false;    
}