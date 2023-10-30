#include<iostream>
using namespace std;

// Problem
/*
    -> Given a string.
    -> Print all it's subsequences.

    -> A subsequence is a group of one or more elements from an array(contiguous or non - contiguous) where order of their occurrence is maintained.
*/

// Solution
/*
    # Method : Include - exclude method
    -> We move from one index to the other where we have two choices - 1. to include the character at index in the subsequence 2. exclude it.
    -> We stop at the last index and print the subsequence thus got. 

*/

void printSubSequence(string s, string res, int index){
    // base case
    if(index >= s.size()){
        cout << res << endl;
        return;
    }

    // function call
    // include
    printSubSequence(s, res + s[index], index + 1);
    // exclude
    printSubSequence(s, res, index + 1); 
}

int main(){
    string s = "abc";
    string result = "";
    printSubSequence(s, result, 0);                 // start from en empty string and index 0
    return 0;
}