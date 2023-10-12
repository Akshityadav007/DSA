#include<iostream>
using namespace std;

// Problem - Leetcode : 680
/*
    Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/

// Solution
/*
    -> # Note: 'at most' here is the key figure to note. This means either 1 or less than that.
    -> Two pointer
    -> We check both the elements
    -> Case 1: Matching
        - low++, high--
       Case 2: Not Matching
        - Need to remove.
        - Which one to remove?              (I failed at this point , also wasn't able to write code for)
        - We can't be sure, hence we keep both the answers and return if any one gives true.
*/

bool checkPalindrome(string str, int low,int high){
    while(low < high){
        if(str[low] != str[high])
            return false;
        low++;high--;
    }
    return true;
}

bool validPalindrome(string s){
    int low = 0,high = s.length() - 1;
    bool removeLow = false,removeHigh = false;

    while(low <= high){
        if(s[low] == s[high]){
            low++;high--;
        }
        else{

            // erase element at low
            removeLow = checkPalindrome(s, low + 1, high);

            // erase element at high
            removeHigh = checkPalindrome(s, low, high - 1);

            return (removeLow || removeHigh);
        }
    }
    // this means it didn't trigger any breaking point
    return true;
}

int main(){
    string s = "abc";
    cout << validPalindrome(s) << endl;

    return 0;
}