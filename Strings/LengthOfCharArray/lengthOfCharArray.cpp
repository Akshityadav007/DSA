#include<iostream>
using namespace std;

// could have made it shorter by removing 'i' variable, but didn't to make you understand

int findLength(char ch[]){
    int length = 0,i = 0;
    // as character array terminates at '\0'
    while(ch[i] != '\0'){
        length++;i++;
    }
    return length;
}

// This is used in operation of character array. E.g Reversal of char array - here if we don't pass exact location of 'low' and 'high', it will start from end of char array.
// And at the end of the char array is '\0'. So, it will terminate then and there.
// Also, to reverse a character array - strrev() is a pre-defined function in C++, defined inside the cstring.h header file.

int main(){
    char ch[100];
    cout << "Enter the char array: " << endl;
    cin.getline(ch,100);

    cout << "Length of char array by my function: " << findLength(ch) << endl;

    // There is a built-in function to get length in the header file 'strings.h' - < Don't know why it ran on my compiler (clang++) without including it>
    cout << "Length of char array by built-in function: " << strlen(ch) << endl;
}