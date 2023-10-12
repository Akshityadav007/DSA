#include<iostream>
using namespace std;

// V.V.V. Important
// Wasn't able to solve this
// Problem || Leetcode : 647
/*
    -> Given a string s, return the number of palindromic substrings in it.
*/

// Solution
/*
    -> In checking palindrome, we used two pointer approach but move from one end towards mid.
    -> In this approach we will have two pointers starting from one point and moving towards edges.
    -> We'll keep checking if while moving we get palindromic substring, once we don't get we move to the next element to start checking.
    -> The palindromic strings are of two size:
        - Odd: In this we start both the pointers from the same point.
        - Even: In this we start the pointers from adjacent points.
    -> Lastly we add both even and odd sized found palindrommic count.

*/

int expand(string st, int p1,int p2){
    int ans = 0;
    while(p1 >= 0 && p2 < st.size() && st[p1] == st[p2]){
        ans++; 
        p1--;p2++;
    }
    return ans;
}

int countSubstrings(string s){
    int totalPalindromes = 0;
    int evenPalindromes = 0,oddPalindromes = 0;

    
    for(int i = 0;i < s.size();i++){
        // Count odd sized palindromic substrings
        evenPalindromes += expand(s,i,i + 1);

        // Count even sized palindromic substrings
        oddPalindromes += expand(s,i,i);
    }
   
    // add both sized palindromes
    totalPalindromes = evenPalindromes + oddPalindromes;
    return totalPalindromes;

    // There was no need of separate variables for even and odd sized palindromes but have put for understanding purpose.

}

int main(){
    string s = "abc";

    return 0;
}