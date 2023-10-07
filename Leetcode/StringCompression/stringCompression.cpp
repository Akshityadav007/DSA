#include<iostream>
using namespace std;

// Problem || Leetcode : 443
/*
    -> Given an array of characters chars, compress it using the following algorithm:
    -> Begin with an empty string s. For each group of consecutive repeating characters in chars:
        - If the group's length is 1, append the character to s.
        - Otherwise, append the character followed by the group's length.
    -> The compressed string s should not be returned separately, but instead, be stored in the input character array chars. 
    -> Note that group lengths that are 10 or longer will be split into multiple characters in chars.

    -> After you are done modifying the input array, return the new length of the array.

    -> You must write an algorithm that uses only constant extra space.
*/

int compress(vector<char>& chars) {
    // empty string
    string s = "";
    int p = 0;          // pointer for every character
    int count = 1;          // to count consecutive occurrence of character - starting with 1 as it is present atleast once.
    // iterate in array which should be atleast of size >= 2
    while(p < chars.size() - 1 && chars.size() > 1){
        if(chars[p] == chars[p + 1])
            count++;
        else{
            s += chars[p];
            if(count > 1)
                s += to_string(count);              // adding count seperately because it only takes single data type in one push
            count = 1;      // reset counter
        }
        p++;
    }
    /*
        -> Two cases for last element:
            - Case 1: It is part of consecutive repeating elements
            - Case 2: It is unique
        -> In both the cases, we can insert the element and it's count yet.
        -> 'p' is at chars.size() - 1.
        -> Note: count is already set for both the cases.
    */
    s += chars[p];
    if(count > 1)
        s += to_string(count);

    // check the size of the chars vector before inserting the compressed string
    if (s.size() > chars.size()) {
        // resize the chars vector
        chars.resize(s.size());
    }

    // now let's insert 's' to original array
    for(int i = 0;i < s.size();i++){
        chars[i] = s[i];
    }
    // return the length of string
    return s.size();
}

int main(){

    return 0;
}