#include<iostream>
using namespace std;

// Print all permutations of a string

/*
    -> Backtracking - exploring all possible ways
        - In backtracking we explore all possible solutions keeping in mind that we don't check the solution that we checked before.

    -> Total no. of permutations = n * (n - 1) * (n - 2) * (n - 3) * ...... 3 * 2 * 1   = n!

    -> Place every character at each different places for permutation.


    -> So, for the first character, we can make n calls;
           for the second character, we can make n - 1 calls;
            .
            .
            .
           for the '(n - 1)th' character, we can make n - (n - 2) = 2 calls;
           for the 'nth' character, we can make n - (n - 1) = 1 call.

    -> This is the main logic! We got it.
    -> In every call, we swap two characters to make a different permutation.

    -> To implement this logic, we'll need two pointers.
        - 1. 'i' pointer to keep it at every position for permutation.
        - 2. 'j' pointer to move to characters after 'i' and swap it to make permutation.
*/

// 1. Method 1) Recursion only (takes more space)
// void printPermutation(string s, int i){
//     // base case
//     if(i >= s.size()){
//         cout << s << " ";
//         return;
//     }
//     for(int j = i; j < s.size(); j++){
//         // create permutation
//         swap(s[i], s[j]);

//         // recursive call
//         printPermutation(s, i + 1);               // pass the permutation to recursive call for the next character
//     }
// }

// 2. Method 2) Recursion + backtracking (takes less space)
void printPermutation(string &s, int i){
    // base case
    if(i >= s.size()){
        cout << s << " ";
        return;
    }
    //          ↓  i got stuck in this initialisation
    for(int j = i; j < s.size(); j++){
        // create permutation
        swap(s[i], s[j]);

        // recursive call   // ↓  i also got stuck here (confused which index to pass)
        printPermutation(s, i + 1);           // pass the permutation to recursive call for the next character

        swap(s[i], s[j]);                       // backtracking - this is done because we are here passing string by reference, so to do undo the changes we do backtracking
    }
}

int main(){
    string s = "abc";
    printPermutation(s, 0);
    cout << endl;

    return 0;
}