#include<iostream>
using namespace std;

// Problem: Replace '@' with whitespace in string

// By default arrays are passed by reference
void replace(char ch[]){
    int i = 0;
    while(ch[i] != '\0'){
        if(ch[i] == '@'){
            ch[i] = ' ';
        }
        i++;
    }
}

int main(){
    // taking char array
    char ch[100];
    cout << "Enter the string: " << endl;
    cin.getline(ch,100);

    cout << "Before: " << ch << endl;
    replace(ch);
    cout << "After: " << ch << endl;



}