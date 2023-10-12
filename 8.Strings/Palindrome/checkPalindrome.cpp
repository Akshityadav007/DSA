#include<iostream>
using namespace std;

// Simply keep matching the characters from front and back.

void changeToUpperCase(char ch[]){
    int i = 0;
    while(ch[i] != '\0'){
        // check if it is a Lower case character
        if(ch[i] >= 'a' && ch[i] <= 'z'){
            // take it to 0 or it's base position (if we take a as base i.e. ASCII - 97) by '-a' and then take it to range of upper case characters by '+A'.
            ch[i] = ch[i] - 'a' + 'A';
            // basically we are doing 'ch - 97 + 65' i.e. 'ch - 32'
        }
        i++;
    }
}


bool isPalindrome(char ch[]){
    // we need to make sure they are all in same case to make this algo case in-sensitive.
    changeToUpperCase(ch);
    int low = 0,high = strlen(ch) - 1;
    // not checking on low == high because at this point they will obviously be equal
    while(low < high){
        // as soon as we get an unequal string return false;
        if(ch[low]!=ch[high])
            return false;
        low++;high--;
    }
    return true;
}

int main(){
    char ch[100];
    cout << "Enter the array: " << endl;
    cin.getline(ch,100);

    if(isPalindrome(ch))
        cout << "It is a palindrome!" << endl;
    else
        cout << "It's not a palindrome." << endl;
    
    return 0; 
}